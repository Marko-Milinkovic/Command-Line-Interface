#include "IOBindingResolver.h"

std::unique_ptr<IOBindingResolver::IOContext> IOBindingResolver::resolve(const std::vector<Token>& tokens) const
{
	
	auto io = std::make_unique<IOContext>();
	
	this->inputSetter(tokens, *io);
	this->outputSetter(tokens, *io);

	return io;

}

void IOBindingResolver::inputSetter(const std::vector<Token>& tokens, IOContext& io) const
{
	bool foundIn = false;
	bool foundInputFile = false;
	bool foundOut = false;

	for (Token t : tokens) { // input setter

		if (t.getParamType() == STRING_ARGUMENT) {
			io.input = std::make_shared<StringInput>(t.getText());
			foundIn = true;
		}
		if (t.getParamType() == TXTFILE_ARGUMENT) {
			io.input = std::make_shared<FileInput>(t.getText());
			foundIn = true;
			foundInputFile = true;
		}
		if (t.getParamType() == INPUT_REDIRECTION && !foundInputFile) {
			io.input = std::make_shared<FileInput>(t.getText());
			foundIn = true;
		}
	}
	if (!foundIn) {
		io.input = std::make_shared<ConsoleInput>();
	}
}

void IOBindingResolver::outputSetter(const std::vector<Token>& tokens, IOContext& io) const
{
	bool foundOut = false;
	
	for (Token t : tokens) { // output setter

		if (t.getParamType() == OUTPUT_REDIRECTION) {
			io.output = std::make_shared<FileOutput>(t.getText());
			foundOut = true;
		}

	}
	if (!foundOut) {
		io.output = std::make_shared<ConsoleOutput>();
	}
}
