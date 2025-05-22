#pragma once
#include "Command.h"

class Validator {

public:

	virtual void validate(const EchoCommand& cmd) = 0;
	virtual void validate(const DateCommand& cmd) = 0;
	virtual void validate(const TimeCommand& cmd) = 0;
	virtual void validate(const TouchCommand& cmd) = 0;
	virtual void validate(const WcCommand& cmd) = 0;
	virtual void validate(const PromptCommand& cmd) = 0;
	virtual void validate(const TruncateCommand& cmd) = 0;
	virtual void validate(const RmCommand& cmd) = 0;
	virtual void validate(const BatchCommand& cmd) = 0;

	virtual ~Validator() = default;

};


