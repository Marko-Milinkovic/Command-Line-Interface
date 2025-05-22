#pragma once
#include "Factory.h"
#include <unordered_map>

class CommandRegistry {

public:

    static CommandRegistry& getInstance();

    void registerCommand(const std::string& name, std::unique_ptr<CommandFactory> factory);

    std::unique_ptr<Command> createCommand(const std::vector<Token>& tokens);

    void populate();

    void debugPrint();


    CommandRegistry(const CommandRegistry&) = delete;
    CommandRegistry& operator=(const CommandRegistry&) = delete;

    CommandRegistry(CommandRegistry&&) = delete;
    CommandRegistry& operator=(CommandRegistry&&) = delete;

private:

    std::unordered_map<std::string, std::unique_ptr<CommandFactory>> factories;
    CommandRegistry() = default;

};
