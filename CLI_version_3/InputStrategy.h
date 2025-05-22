#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

class InputStrategy {

public:

	virtual std::istream& getInStream() = 0;
	virtual ~InputStrategy() = default;

};


class ConsoleInput : public InputStrategy {

public:
    std::istream& getInStream() override {
        return std::cin;
    }
};


class StringInput : public InputStrategy {

    std::istringstream ss;

public:

    StringInput(const std::string& data) : ss(data) {}
    
    std::istream& getInStream() override {
        return ss;
    }
};


class FileInput : public InputStrategy {

    std::ifstream file;

public:

    FileInput(const std::string& path) {
        file.open(path);
    }

    std::istream& getInStream() override {
        return file;
    }
};
