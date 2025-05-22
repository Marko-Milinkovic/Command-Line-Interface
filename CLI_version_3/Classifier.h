#pragma once
#include "Tokenizer.h"
#include <unordered_map>
#include <functional>
#include "CLIError.h"


class Classifier {

public:

	static Classifier& getInstance();

	void populate();

	void classify(std::vector<Token>& tokens);

	Classifier(const Classifier&) = delete;
	Classifier& operator=(const Classifier&) = delete;

	Classifier(Classifier&&) = delete;
	Classifier& operator=(Classifier&&) = delete;

private:
	
	std::unordered_map<std::string, std::function<void(std::vector<Token>&)>> classifiers;

	static void OC_ArgumentOptional(std::vector<Token>& tokens);
	static void OC(std::vector<Token>& tokens);
	static void OC_Filename(std::vector<Token>& tokens);
	static void OC_Option_ArgumentOptional(std::vector<Token>& tokens);
	static void OC_StringArgument(std::vector<Token>& tokens);
	//static void OC_ArgumentOptional_String1_String2Optional(std::vector<Token>& tokens);

	Classifier() = default;

};