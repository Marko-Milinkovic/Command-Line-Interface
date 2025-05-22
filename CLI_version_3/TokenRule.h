#pragma once
#include "Tokenizer.h"
#include "CLIError.h"

class TokenRule {
public:

    virtual ~TokenRule() = default;
    virtual void check(const Token& token) const = 0;
    virtual std::string getErrorMessage() const = 0;

};

class NoInvalidCharactersRule : public TokenRule {
public:

    void check(const Token& token) const override;
    std::string getErrorMessage() const override;

};

class NoBigLetters : public TokenRule {
public:
    
    void check(const Token& token) const override;
    std::string getErrorMessage() const override;

};

class NoUndefinedRule : public TokenRule {
public:

    void check(const Token& token) const override;
    std::string getErrorMessage() const override;

};

class NoTxtRule : public TokenRule {
public:

    void check(const Token& token) const override;
    std::string getErrorMessage() const override;

};