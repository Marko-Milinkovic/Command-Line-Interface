#pragma once
#include <vector>
#include <string>
#include <iostream>

enum LexemType {

	OC,
	OPT,
	TXTFILE,
	STRING,
	INREDIRECT,
	OUTREDIRECT,
	UNDEFINED
};

static const char* LexemTypesStrings[] = {

	"OC",
	"OPT",
	"TXTFILE",
	"STRING",
	"INREDIRECT",
	"OUTREDIRECT",
	"UNDEFINED"
	
};

enum ParamType {

	OPERATION_CODE,
	OPTION,
	TXTFILE_ARGUMENT,
	FILENAME,
	STRING_ARGUMENT,
	OTHER,
	INPUT_REDIRECTION,
	OUTPUT_REDIRECTION

};

static const char* ParamTypesStrings[] = {

	"OPERATION CODE",
	"OPTION",
	"TXTFILE ARGUMENT",
	"FILENAME",
	"STRING ARGUMENT",
	"OTHER",
	"INPUT_REDIRECTION",
	"OUTPUT_REDIRECTION"

};

class Token {

public:

	virtual void debugPrint() const;

	LexemType getLexemType() const;
	void setLexemType(LexemType t);

	ParamType getParamType() const;
	void setParamType(ParamType p);

	void setText(const std::string txt);
	std::string& getText(); // mutable
	const std::string& getText() const; // read only

private:

	enum LexemType L_type;
	enum ParamType P_type;
	std::string mText;

};

class Tokenizer {

public:

	std::vector<Token> parse(const std::string& inputLine);

	LexemType getCurrentState() const;
	void setCurrentState(LexemType t);

private:

	void endToken(Token& token, std::vector<Token>& tokens);

	LexemType currentState;

};



