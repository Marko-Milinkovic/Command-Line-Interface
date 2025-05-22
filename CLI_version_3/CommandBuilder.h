#pragma once
#include "Tokenizer.h"
#include "IOBindingResolver.h"
#include "CLIError.h"

class Command;

class CommandBuilder {

public:

	CommandBuilder& setParameters(const std::vector<Token>& tokens);
	CommandBuilder& setFlags(const std::vector<Token>& tokens);
	CommandBuilder& setIO(const std::vector<Token>& tokens);
	CommandBuilder& checkFlags();

	template<typename T>
	std::unique_ptr<Command> build();

private:

	std::vector<Token> tokens;

	std::shared_ptr<InputStrategy> input;
	std::shared_ptr<OutputStrategy> output;

	Token opcode;
	Token option;
	std::vector<Token> arguments;
	std::vector<Token> other;
	
	bool redirectedInput = false;
	bool redirectedOutput = false;
	bool hasArg = false;


	void sortTokens();

};

template<typename T>
inline std::unique_ptr<Command> CommandBuilder::build()
{	
	std::cout << "All set up for command creation, calling constructor" << std::endl;
	return std::make_unique<T>(opcode, option, arguments, other, std::move(input), std::move(output), redirectedInput, redirectedOutput, hasArg);
}



