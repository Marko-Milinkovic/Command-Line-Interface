#include "CLIEngine.h"

CLIEngine& CLIEngine::getInstance()
{
	static CLIEngine instance;
	return instance;
}

void CLIEngine::run()
{
	
	while (true) {

		std:: string commandLine = this->getCommandLine();
		std::vector<std::string> commands = StringSplitter().split(commandLine);

		for (const auto& command : commands) {
			
			try {
				
				auto tokens = this->preproccessingOfCommand(command);
				auto CLIcmd = this->commandProduction(tokens);
				this->addCommandToPipeline(std::move(CLIcmd));

			}
			catch (const CLIError& e) {
				
				std::cerr << e.what() << std::endl;
				this->resetPipeline();
				continue;
			
			}

		}

		if (pipeline->getSize() == 0) { continue; }

		try {

			this->configurePipeline();
			
			this->pipelineSemanticChecking();
			this->pipelineExecution();

		}
		catch (SemanticError e) {

			std::cerr << e.what() << std::endl;
		
		}
		
		this->resetPipeline();
	}

}

void CLIEngine::addCommandLine(const std::string line)
{
	this->commandLines.push(line);
}

std::string CLIEngine::getPrompt() const
{
	return this->prompt;;
}

void CLIEngine::setPrompt(std::string s)
{
	this->prompt = s;
}

std::string CLIEngine::getCommandLine()
{
	std::string line;
	if (this->commandLines.empty()) {
		std::cout << this->getPrompt() << " ";
		std::getline(std::cin, line);
	}
	else {
		line = commandLines.front();
		this->commandLines.pop();
	}
	return line;
}

std::vector<Token> CLIEngine::preproccessingOfCommand(const std::string& command)
{
	std::cout << "PREPROCCESSING OF COMMAND: " << std::endl;
	std::vector<Token> tkns = this->tokenizer->parse(command);
	this->tokenChecker->validate(tkns); // throws lexical errors

	// syntax checking missing !!!

	Classifier::getInstance().classify(tkns); // trows semantic errors

	for (Token t : tkns) {
		t.debugPrint();
	}

	return tkns;
}

std::unique_ptr<Command> CLIEngine::commandProduction(const std::vector<Token>& tokens)
{
	std::cout << "COMMAND PRODUCTION" << std::endl;
	auto cmd = CommandRegistry::getInstance().createCommand(tokens);
	cmd->debugPrint();
	return cmd;
}

void CLIEngine::addCommandToPipeline(std::unique_ptr<Command> command)
{
	std::cout << "ADDING COMMAND TO PIPELINE" << std::endl;
	pipeline->append(std::move(command));
	std::cout << "---------------------------------------------------------------" << std::endl;
}

void CLIEngine::configurePipeline()
{
	std::cout << "PIPELINE CONFIGURATION" << std::endl;
	pipeline->configure();
}

void CLIEngine::resetPipeline()
{
	this->pipeline->clear();
}

void CLIEngine::pipelineSemanticChecking()
{
	const auto& commands = pipeline->getCommands();
	this->semanticChecker->validate(commands); 
}

void CLIEngine::pipelineExecution()
{
	std::cout << "PIPELINE EXECUTION" << std::endl;

	std::cout << "PIPELINE LOOK" << std::endl;
	pipeline->debugPrint();
	
	pipeline->executeAll();
	std::cout << std::endl << std::endl;
}

