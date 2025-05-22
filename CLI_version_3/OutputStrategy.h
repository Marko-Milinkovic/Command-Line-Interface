#pragma once
#include "InputStrategy.h"

class OutputStrategy {

public:
    virtual std::ostream& getOutStream() = 0;
    virtual ~OutputStrategy() = default;

};


class ConsoleOutput : public OutputStrategy {

public:

    std::ostream& getOutStream() override {
        return std::cout;
    }
};


class FileOutput : public OutputStrategy {

    std::ofstream file;

public:

    FileOutput(const std::string& path) {
        file.open(path);
    }

    std::ostream& getOutStream() override {
        return file;
    }
};

class StringOutput : public OutputStrategy {
    std::stringstream buffer;

public:
    std::ostream& getOutStream() override {
        return buffer;
    }

    std::string getContent() const {
        return buffer.str();
    }
};