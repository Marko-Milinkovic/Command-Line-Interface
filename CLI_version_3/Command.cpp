#include "Command.h"
#include "Validator.h"
#include "CLIEngine.h"
#include <ctime>
#include <iostream>
#include <iomanip>

void EchoCommand::execute()
{	
	this->ensureArgument();

	std::string line;
	while (std::getline(this->input->getInStream(), line)) {
		this->output->getOutStream() << line << std::endl;
	}
}

void TimeCommand::execute()
{
	std::time_t now = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &now);
	output->getOutStream() << std::put_time(&localTime, "%H:%M:%S") << std::endl;
}

void DateCommand::execute()
{
	std::time_t now = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &now);
	this->output->getOutStream() << std::put_time(&localTime, "%Y-%m-%d") << std::endl;
}

void TouchCommand::execute()
{
	
	std::string filename = this->other[0].getText();
	std::ifstream infile(filename);

	if (infile.good()) {
		std::cout << "File " + filename + " already exists!" << std::endl; // should be changed to throw exception
		return;
	}

	std::ofstream outfile(filename);
	if (!outfile) {
		// file failed to create OS exception
	}
	else {
		std::cout << "File " + filename + " created" << std::endl;
	}

}

void WcCommand::execute()
{
	this->ensureArgument();

	std::string line;
	int wordCount = 0;
	int charCount = 0;

	while (std::getline(this->input->getInStream(), line)) {
		
		charCount += static_cast<int>(line.size()) + 1;

		std::istringstream iss(line);
		std::string word;
		while (iss >> word) {
			++wordCount;
		}
	}

	if (this->option.getText() == "w") { this->output->getOutStream() << wordCount << std::endl; }
	else if (this->option.getText() == "c") { this->output->getOutStream() << charCount - 1 << std::endl; }
	else {
		// throw Semantic error
	}
	return;
}

void PromptCommand::execute()
{
	std::string prompt;
	this->input->getInStream() >> prompt;
	CLIEngine::getInstance().setPrompt(prompt);

	return;
}

void TruncateCommand::execute()
{	
	const std::string& filename = other[0].getText();
	std::ifstream file(filename);

	if (!file.good()) {
		std::cout << "File " + filename + " does not exist!" << std::endl; // should be changed to throw exception
		return;
	}
	file.close();

	std::ofstream ofs(filename, std::ios::trunc);
	if (!ofs.good()) {
		std::cout << "Failed to delete content of a file " + filename << std::endl; // should be changed to throw exception
	}
	return;
}

void RmCommand::execute()
{
	const std::string& filename = this->other[0].getText();
	std::ifstream file(filename);

	if (!file.good()) {
		std::cout << "File " + filename + " does not exist!" << std::endl; // should be changed to throw exception
		return;
	}
	file.close();

	if (std::remove(filename.c_str()) != 0) {
		std::cout << "Failed to delete a file!" << std::endl; // should be changed to throw exception
	}
	else {
		std::cout << "File " + filename + " deleted\n";
	}

	return;
}

void BatchCommand::execute()
{
	this->ensureArgument();

	std::string line;
	while (std::getline(this->input->getInStream(), line)) {
		CLIEngine::getInstance().addCommandLine(line);
	}

	return;
}

void HeadCommand::execute()
{	
	this->ensureArgument();

	std::string opt = this->option.getText();

	if (opt.length() > 6 || opt[0] != 'n') {
		// Semantic error option invalid
	}

	int lineCount = std::stoi(opt.substr(1));
	std::string line;
	for (int i = 0; i < lineCount && std::getline(this->input->getInStream(), line); i++) {
		this->output->getOutStream() << line << '\n';
	}
}


void Command::ensureArgument()
{
	if (dynamic_cast<ConsoleInput*>(input.get())) {

		std::string userInput;
		std::string line;

		while (std::getline(input->getInStream(), line)) {
			userInput += line + '\n';
		}

		input = std::make_unique<StringInput>(userInput);
		std::cin.clear();

	}
}


void Command::debugPrint()
{
	std::cout << "Command " + this->opcode.getText() + " successfully created" << std::endl;
	std::cout << "Flags: " << std::endl;
	std::cout << "Has argument: " << std::boolalpha << this->hasArgument << std::endl;
	std::cout << "Has redirected input: " << std::boolalpha << this->hasRedirectedInput << std::endl;
	std::cout << "Has redirected output: " << std::boolalpha << this->hasRedirectedOutput << std::endl;
}


void EchoCommand::accept(Validator& v) const
{
	v.validate(*this);
}


void DateCommand::accept(Validator& v) const
{
	v.validate(*this);
}


void TimeCommand::accept(Validator& v) const
{
	v.validate(*this);
}


void TouchCommand::accept(Validator& v) const
{
	v.validate(*this);
}


void WcCommand::accept(Validator& v) const
{
	v.validate(*this);
}

void PromptCommand::accept(Validator& v) const
{
	v.validate(*this);
}

void TruncateCommand::accept(Validator& v) const
{
	v.validate(*this);
}


void RmCommand::accept(Validator& v) const
{
	v.validate(*this);
}

void BatchCommand::accept(Validator& v) const
{
	v.validate(*this);
}

void HeadCommand::accept(Validator& v) const
{
}
