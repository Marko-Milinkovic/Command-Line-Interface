#include "Classifier.h"

//std::unordered_map<std::string, std::function<void(std::vector<Token>&)>> Classifier::classifiers;


Classifier& Classifier::getInstance()
{
    static Classifier classifier;
    return classifier;
}

void Classifier::populate()
{
    classifiers["echo"] = this->OC_ArgumentOptional;
    classifiers["time"] = this->OC;
    classifiers["date"] = this->OC;
    classifiers["touch"] = this->OC_Filename;
    classifiers["wc"] = this->OC_Option_ArgumentOptional;
    classifiers["prompt"] = this->OC_StringArgument;
    classifiers["truncate"] = this->OC_Filename;
    classifiers["rm"] = this->OC_Filename;
    classifiers["batch"] = this->OC_ArgumentOptional;
    classifiers["head"] = this->OC_Option_ArgumentOptional;
}

void Classifier::classify(std::vector<Token>& tokens)
{
    if (tokens.empty()) {
        return;
    }

    auto it = classifiers.find(tokens[0].getText());
    if (it != classifiers.end()) {
        it->second(tokens);
    }
    else {
        throw UnkownCommandError(tokens[0].getText());
    }

}

void Classifier::OC_ArgumentOptional(std::vector<Token>& tokens)
{
    size_t size = tokens.size();

    tokens[0].setParamType(OPERATION_CODE);

    if (size > 3) {
        throw SemanticError("Too many tokens in " + tokens[0].getText() + " command\n");
    }

    if (size >= 2) {

        if (tokens[1].getLexemType() == TXTFILE) {
            tokens[1].setParamType(TXTFILE_ARGUMENT);
        }
        else if (tokens[1].getLexemType() == STRING) {
            tokens[1].setParamType(STRING_ARGUMENT);
        }
        else if (tokens[1].getLexemType() == INREDIRECT) {
            tokens[1].setParamType(INPUT_REDIRECTION);
        }
        else if (tokens[1].getLexemType() == OUTREDIRECT) {
            tokens[1].setParamType(OUTPUT_REDIRECTION);
        }
        else {
            throw SemanticError("Invalid token at position 2 in command " + tokens[0].getText() + "\n");
        }
    }
    if (size == 3) {

        if (tokens[2].getLexemType() == OUTREDIRECT) {
            tokens[2].setParamType(OUTPUT_REDIRECTION);
        }
        else if (tokens[1].getLexemType() == INREDIRECT) {
            tokens[1].setParamType(INPUT_REDIRECTION);
        }
        else {
            throw SemanticError("Invalid token at position 3 in command " + tokens[0].getText() + "\n");
        }
    }

}

void Classifier::OC(std::vector<Token>& tokens)
{
    size_t size = tokens.size();
    tokens[0].setParamType(OPERATION_CODE);

    if (size == 2) {

        if (tokens[1].getLexemType() == OUTREDIRECT) {
            tokens[1].setParamType(OUTPUT_REDIRECTION);
        }
        else {
            throw SemanticError("Invalid token at position 2 in command " + tokens[0].getText() + "\n");
        }
    }
    if (size > 2) {
        throw SemanticError("Too many tokens in " + tokens[0].getText() + "command\n");
    }
}

void Classifier::OC_Filename(std::vector<Token>& tokens)
{
    size_t size = tokens.size();
    tokens[0].setParamType(OPERATION_CODE);

    if (size == 2) {

        if (tokens[1].getLexemType() == TXTFILE) {
            tokens[1].setParamType(FILENAME);
        }
        else {
            throw SemanticError("Invalid token at position 2 in command " + tokens[0].getText() + "\n");
        }

    }
    else {
        throw SemanticError("Too many or too few tokens in " + tokens[0].getText() + " command\n");
    }
}

void Classifier::OC_Option_ArgumentOptional(std::vector<Token>& tokens)
{
    size_t size = tokens.size();

    if (size < 2) {
        throw SemanticError("Too few tokens in " + tokens[0].getText() + "command\n");
    }
    if (size > 4) {
        throw SemanticError("Too many tokens in " + tokens[0].getText() + "command\n");
    }

    tokens[0].setParamType(OPERATION_CODE);

    if (tokens[1].getLexemType() == OPT) {
        tokens[1].setParamType(OPTION);
    }
    else {
        throw SemanticError("Invalid token at position 1 in command " + tokens[0].getText() + "\n");
    }

    if (size >= 3) {

        if (tokens[2].getLexemType() == TXTFILE) {
            tokens[2].setParamType(TXTFILE_ARGUMENT);
        }
        else if (tokens[2].getLexemType() == STRING) {
            tokens[2].setParamType(STRING_ARGUMENT);
        }

        else if (tokens[2].getLexemType() == INREDIRECT) {
            tokens[2].setParamType(INPUT_REDIRECTION);
        }
        else if (tokens[2].getLexemType() == OUTREDIRECT) {
            tokens[2].setParamType(OUTPUT_REDIRECTION);
        }
        else {
            throw SemanticError("Invalid token at position 3 in command " + tokens[0].getText() + "\n");
        }
    }

    if (size == 4) {

        if (tokens[3].getLexemType() == INREDIRECT) {
            tokens[3].setParamType(INPUT_REDIRECTION);
        }
        else if (tokens[3].getLexemType() == OUTREDIRECT) {
            tokens[3].setParamType(OUTPUT_REDIRECTION);
        }
        else {
            throw SemanticError("Invalid token at position 3 in command " + tokens[0].getText() + "\n");
        }
    }
}

void Classifier::OC_StringArgument(std::vector<Token>& tokens)
{
    size_t size = tokens.size();
    if (size != 2) {
        throw SemanticError("Too many or too few tokens in " + tokens[0].getText() + " command\n");
    }

    tokens[0].setParamType(OPERATION_CODE);
    if (tokens[1].getLexemType() == STRING) {
        tokens[1].setParamType(STRING_ARGUMENT);
    }
    else {
        throw SemanticError("Invalid token at position 1 in command " + tokens[0].getText() + "\n");
    }
}

