#pragma once
#include "Tokenizer.h"
#include "IOBindingResolver.h"
#include <memory>


class Validator;
class CommandBuilder;

class Command {

    friend class CommandBuilder;

public:

    virtual void execute() = 0;
    virtual void accept(Validator& v) const = 0;

    Command(Token opcode, Token option, std::vector<Token> arguments, std::vector<Token> other, std::shared_ptr<InputStrategy> in, std::shared_ptr<OutputStrategy> out, bool redirectedIn, bool redirectedOut, bool hasArg) :
        opcode(std::move(opcode)),
        option(std::move(option)),
        arguments(std::move(arguments)),
        other(std::move(other)),
        input(std::move(in)),
        output(std::move(out)) { this->hasRedirectedInput = redirectedIn, this->hasRedirectedOutput = redirectedOut, this->hasArgument = hasArg;
    }

    void ensureArgument();
    void debugPrint();

    const Token& getOpcode() const { return opcode; }
    const Token& getOption() const { return option; }
    const std::vector<Token>& getArguments() const { return arguments; }

    std::shared_ptr<InputStrategy> getInput() const { return input; }
    std::shared_ptr<OutputStrategy> getOutput() const { return output; }

    void setInput(std::shared_ptr<InputStrategy> in) { input = std::move(in); }
    void setOutput(std::shared_ptr<OutputStrategy> out) { output = std::move(out); }


    bool getHasRedirectedInput() const { return this->hasRedirectedInput; };
    bool getHasRedirectedOutput() const { return this->hasRedirectedOutput; };
    bool getIsInPipeline() const { return this->isInPipeline; };
    bool getHasArgument() const { return this->hasArgument; };
    bool getFirstInPipeline() const { return this->firstInPipeline; }
    bool getLastInPipeline() const { return this->lastInPipeline; }


    void setHasRedirectedInput(bool value) { this->hasRedirectedInput = value; };
    void setHasRedirectedOutput(bool value) { this->hasRedirectedOutput = value; };
    void setIsInPipeline(bool value) { this->isInPipeline = value; };
    void setHasArgument(bool value) { this->hasArgument = value; };
    void setFirstInPipeline(bool value) { this->firstInPipeline = value; }
    void setLastInPipeline(bool value) { this->lastInPipeline = value; }
    
protected:

    Token opcode;
    Token option;
    std::vector<Token> arguments;
    std::vector<Token> other;

    std::shared_ptr<InputStrategy> input;
    std::shared_ptr<OutputStrategy> output;

    bool hasRedirectedInput = false;
    bool hasRedirectedOutput =  false;
    bool isInPipeline = false;
    bool hasArgument = false;

    bool firstInPipeline = false;
    bool lastInPipeline = false;

};


class EchoCommand : public Command {

public:
    
    using Command::Command;

    void execute() override;
    void accept(Validator& v) const override;

};

class TimeCommand : public Command {

public:

    using Command::Command;

    void execute() override;
    void accept(Validator& v) const override;

};

class DateCommand : public Command {

public:

    using Command::Command;

    void execute() override;
    void accept(Validator& v) const override;

};

class TouchCommand : public Command {

public:

    using Command::Command;

    void execute() override;
    void accept(Validator& v) const override;

};

class WcCommand : public Command {

public:

    using Command::Command;

    void execute() override;
    void accept(Validator& v) const override;

};

class PromptCommand : public Command {

public:

    using Command::Command;

    void execute() override;
    void accept(Validator& v) const override;

};

class TruncateCommand : public Command {

public:

    using Command::Command;

    void execute() override;
    void accept(Validator& v) const override;

};

class RmCommand : public Command {

public:

    using Command::Command;

    void execute() override;
    void accept(Validator& v) const override;

};

class BatchCommand : public Command {

public:

    using Command::Command;

    void execute() override;
    void accept(Validator& v) const override;

};

class HeadCommand : public Command {

public:

    using Command::Command;

    void execute() override;
    void accept(Validator& v) const override;

};
