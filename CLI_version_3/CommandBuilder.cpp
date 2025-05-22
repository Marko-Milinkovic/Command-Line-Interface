#include "CommandBuilder.h"
#include "Command.h"

CommandBuilder& CommandBuilder::setParameters(const std::vector<Token>& tokens)
{
    this->tokens = tokens;
    this->sortTokens();
    return *this;
}

CommandBuilder& CommandBuilder::setFlags(const std::vector<Token>& tokens)
{
    for (const auto& token : tokens) {
        if (token.getParamType() == INPUT_REDIRECTION) {
            this->redirectedInput = true;
        }
        if (token.getParamType() == OUTPUT_REDIRECTION) {
            this->redirectedOutput = true;
        }
        if (token.getParamType() == STRING_ARGUMENT || token.getParamType() == TXTFILE_ARGUMENT) {
            this->hasArg = true;
        }
    }
    return *this;
}

CommandBuilder& CommandBuilder::setIO(const std::vector<Token>& tokens)
{    
    IOBindingResolver resolver;
    std::unique_ptr<IOBindingResolver::IOContext> io =  resolver.resolve(tokens);

    this->input = std::move(io->input);
    this->output = std::move(io->output);
    
    std::cout << "Input strategy type: " << typeid(*input).name() << std::endl;
    std::cout << "Output strategy type: " << typeid(*output).name() << std::endl;

    return *this;
}

CommandBuilder& CommandBuilder::checkFlags()
{
    if (this->hasArg && this->redirectedInput) {
        throw SemanticError("Command " + this->opcode.getText() + " cannot have both argument and input redirected\n");
    }
    return *this;
}

void CommandBuilder::sortTokens()
{   
    std::cout << "Tokens are being classified" << std::endl;
    for (Token t : tokens) {

        if (t.getParamType() == OPERATION_CODE) {
            this->opcode = t;
        }
        if (t.getParamType() == OPTION) {
            this->option = t;
        }
        if (t.getParamType() == STRING_ARGUMENT || t.getParamType() == TXTFILE_ARGUMENT) {
            this->arguments.push_back(t);
        }
        if (t.getParamType() == INPUT_REDIRECTION) {
            this->arguments.push_back(t);
        }
        if (t.getParamType() == OUTPUT_REDIRECTION) {
            this->arguments.push_back(t);
        }
        if (t.getParamType() == OTHER || t.getParamType() == FILENAME) {
            this->other.push_back(t);
        }
    }
}

template std::unique_ptr<Command> CommandBuilder::build<EchoCommand>();
template std::unique_ptr<Command> CommandBuilder::build<TimeCommand>();
template std::unique_ptr<Command> CommandBuilder::build<DateCommand>();
template std::unique_ptr<Command> CommandBuilder::build<TouchCommand>();
template std::unique_ptr<Command> CommandBuilder::build<WcCommand>();
template std::unique_ptr<Command> CommandBuilder::build<PromptCommand>();
template std::unique_ptr<Command> CommandBuilder::build<TruncateCommand>();
template std::unique_ptr<Command> CommandBuilder::build<RmCommand>();
template std::unique_ptr<Command> CommandBuilder::build<BatchCommand>();
template std::unique_ptr<Command> CommandBuilder::build<HeadCommand>();