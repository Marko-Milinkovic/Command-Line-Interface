#pragma once
#include "Command.h"
#include "CLIError.h"

class SemanticRule {

public:

	virtual ~SemanticRule() = default;
	virtual void check(const Command& cmd) const = 0;

};


class NoHasArgumentAndInPipeline : public SemanticRule {

public:

	void check(const Command& cmd) const override;

};

class NoRedirectionAndInPipeline : public SemanticRule {

public:

	void check(const Command& cmd) const override;

};



