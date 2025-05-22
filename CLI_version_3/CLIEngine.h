#pragma once
#include "memory"
#include "TokenChecker.h"
#include "SemanticChecker.h"
#include "Pipeline.h"
#include "CommandRegistry.h"
#include "Classifier.h"
#include "StringSplitter.h"
#include <queue>


class CLIEngine {

public:

    static CLIEngine& getInstance();

    void run();

    void addCommandLine(const std::string line);

    std::string getPrompt() const;
    void setPrompt(std::string c);

private:

    std::unique_ptr<Tokenizer> tokenizer;
    std::unique_ptr<TokenChecker> tokenChecker;
    std::unique_ptr<SemanticChecker> semanticChecker;
    std::unique_ptr<Pipeline> pipeline;

    std::string prompt = "$";

    std::queue<std::string> commandLines;

    CLIEngine() :
        tokenizer(std::make_unique<Tokenizer>()),
        tokenChecker(std::make_unique<TokenChecker>()),
        semanticChecker(std::make_unique<SemanticChecker>()),
        pipeline(std::make_unique<Pipeline>())
    {
        Classifier::getInstance().populate();
        CommandRegistry::getInstance().populate();
        tokenChecker->populate();
        semanticChecker->populate();
    }

    std::string getCommandLine();
    std::vector<Token>preproccessingOfCommand(const std::string& command);
    std::unique_ptr<Command>commandProduction(const std::vector<Token>& tokens);
    void addCommandToPipeline(std::unique_ptr<Command> command);
    void configurePipeline();
    void pipelineSemanticChecking();
    void pipelineExecution();

    void resetPipeline();
    
};