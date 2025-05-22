#include "SemanticChecker.h"

void SemanticChecker::validate(const std::vector<const Command*> commands) const
{	
	for (const auto& cmd : commands) {
		for (const auto& rule : rules) {
			rule->check(*cmd);
		}
	}
}

void SemanticChecker::populate()
{
	this->addRule(std::make_unique<NoRedirectionAndInPipeline>());
	this->addRule(std::make_unique<NoHasArgumentAndInPipeline>());
}

void SemanticChecker::addRule(std::unique_ptr<SemanticRule> rule)
{
	this->rules.push_back(std::move(rule));
}
