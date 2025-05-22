#pragma once
#include <string>
#include <stdexcept>
#include <exception>

class CLIError : public std::runtime_error {

public:

	CLIError(const std::string& message) : std::runtime_error(message) {}

};

class LexicalError : public CLIError {

public:

	LexicalError(const std::string& message) : CLIError("Lexical error: " + message) {}

};

class SyntaxError : public CLIError {

public:

	SyntaxError(const std::string& message) : CLIError("Syntax error: " + message) {}

};

class SemanticError : public CLIError {

public:

	SemanticError(const std::string& message) : CLIError("Semantic error: " + message) {}

};

class UnkownCommandError : public CLIError {

public:

	UnkownCommandError(const std::string& message) : CLIError("Unknown command error: " + message) {}

};
