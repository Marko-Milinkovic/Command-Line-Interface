#pragma once
#include "TokenRule.h"

class TokenChecker {

public:

	void validate(const std::vector<Token>& tokens) const;
	void populate();

private:

	void addRule(std::unique_ptr<TokenRule> rule);

	std::vector<std::unique_ptr<TokenRule>> rules;

};
