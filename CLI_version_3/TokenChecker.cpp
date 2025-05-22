#include "TokenChecker.h"

void TokenChecker::validate(const std::vector<Token>& tokens) const
{
	for (const auto& token : tokens) {
		for (const auto& rule : rules) {
			rule->check(token);
		}
	}
}

void TokenChecker::populate()
{
	this->addRule(std::make_unique<NoUndefinedRule>());
	this->addRule(std::make_unique<NoInvalidCharactersRule>());
	this->addRule(std::make_unique<NoBigLetters>());
	this->addRule(std::make_unique<NoTxtRule>());
}

void TokenChecker::addRule(std::unique_ptr<TokenRule> rule)
{
	this->rules.push_back(std::move(rule));
}
