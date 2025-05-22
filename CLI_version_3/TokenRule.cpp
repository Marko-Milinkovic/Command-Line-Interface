#include "TokenRule.h"

void NoInvalidCharactersRule::check(const Token& token) const
{
    if (token.getLexemType() == STRING) { return; }

    const std::string line = token.getText();
    for (char c : line) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != '.' && !std::isdigit(static_cast<unsigned char>(c))) {
            throw LexicalError("Invalid character '" + std::string(1, c) + "' in token " + line + "\n");
        }
    }
    return;
}

std::string NoInvalidCharactersRule::getErrorMessage() const
{
    return "Token contains invalid characters\n";
}

void NoBigLetters::check(const Token& token) const
{
    if (token.getLexemType() == STRING) { return; }

    if (token.getLexemType() == OC || token.getLexemType() == OPT) {
        
        const std::string line = token.getText();
        for (char c : line) {
            if (isupper(static_cast<unsigned char>(c))) {
                throw LexicalError("Operation code and option of command cannot contain big letters\n");
            }
        }
    }
    return;
}

std::string NoBigLetters::getErrorMessage() const
{
    return "Token contains big letters\n";
}

void NoUndefinedRule::check(const Token& token) const
{
    if (token.getLexemType() == UNDEFINED) { throw LexicalError("Token " + token.getText() + " is undefined"); }
    return;
}

std::string NoUndefinedRule::getErrorMessage() const
{
    return "Token is undefined\n";
}

void NoTxtRule::check(const Token& token) const
{
    if (token.getLexemType() != TXTFILE && token.getLexemType() != INREDIRECT && token.getLexemType() != OUTREDIRECT) {
        return;
    }
    
    const std::string line = token.getText();
    char target = '.';
    size_t position = line.find(target);

    const std::string extension = line.substr(position + 1);

    if (extension != "txt") {
        throw LexicalError("Invalid file extension '" + extension + "'\n");
    }

}

std::string NoTxtRule::getErrorMessage() const
{
    return "Wrong file extension";
}
