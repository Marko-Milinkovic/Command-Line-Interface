#pragma once
#include "Command.h"
#include "CommandBuilder.h"

class CommandFactory {

public:

	virtual std::unique_ptr<Command> create(const std::vector<Token>& tokens) const = 0;

	virtual ~CommandFactory() = default;

};


template<typename T>
class TemplateCommandFactory : public CommandFactory {

public:

	std::unique_ptr<Command> create(const std::vector<Token>& tokens) const override;

};


template<typename T>
inline std::unique_ptr<Command> TemplateCommandFactory<T>::create(const std::vector<Token>& tokens) const
{	
	CommandBuilder builder;
	return builder.setParameters(tokens).setFlags(tokens).setIO(tokens).checkFlags().build<T>();
}



