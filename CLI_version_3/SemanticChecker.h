#pragma once
#include "SemanticRule.h"

class SemanticChecker {

public:

	void validate(const std::vector<const Command*> commands) const;
	void populate();

private:

	void addRule(std::unique_ptr<SemanticRule> rule);
	std::vector<std::unique_ptr<SemanticRule>> rules;

};
