#include "Tokenizer.h"

void Token::debugPrint() const
{
	std::cout << "Token(" << LexemTypesStrings[L_type] << "," << ParamTypesStrings[P_type] << "," << mText << ")" << std::endl;
}

LexemType Token::getLexemType() const
{
	return this->L_type;
}

void Token::setLexemType(LexemType t)
{
	this->L_type = t;
}

ParamType Token::getParamType() const
{
	return this->P_type;
}

void Token::setParamType(ParamType p)
{
	this->P_type = p;
}


void Token::setText(const std::string txt)
{
	this->mText = txt;
}

std::string& Token::getText()
{
	return this->mText;
}

const std::string& Token::getText() const
{
	return this->mText;
}

LexemType Tokenizer::getCurrentState() const
{
	return this->currentState;
}

void Tokenizer::setCurrentState(LexemType t)
{
	this->currentState = t;
}

std::vector<Token> Tokenizer::parse(const std::string& inputLine)
{
	Token currentToken;
	std::vector<Token> tokens;

	this->setCurrentState(OC);

	for (char currCh : inputLine) {
		
		switch (currCh)
		{
		case ' ':
		case '\t':

			if (this->currentState != STRING) {
				endToken(currentToken, tokens);
			}
			else {
				currentToken.getText().append(1, currCh);
			}

			break;

		case '-':

			this->currentState = OPT;
			break;

		case '"':

			if (this->currentState == STRING) {
				endToken(currentToken, tokens);
			}
			else {
				endToken(currentToken, tokens);
				this->currentState = STRING;
			}

			break;

		case '.':

			currentToken.getText().append(1, currCh);
			if (this->currentState != STRING && this->currentState != INREDIRECT && this->currentState != OUTREDIRECT) {
				this->currentState = TXTFILE;
			}
			break;

		case '\n':
		case '\r':

			endToken(currentToken, tokens);
			break;

		case '<':

			this->currentState = INREDIRECT;
			break;

		case '>':

			this->currentState = OUTREDIRECT;
			break;

		default:
			
			currentToken.getText().append(1, currCh);
			break;

		}

	}

	endToken(currentToken, tokens);
	return tokens;

}

void Tokenizer::endToken(Token& token, std::vector<Token>& tokens)
{
	
	if (!token.getText().empty()) {
		token.setLexemType(this->currentState);
		tokens.push_back(token);
		token.getText().clear();
	}

	this->currentState = UNDEFINED;

}



