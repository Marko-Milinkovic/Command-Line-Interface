#include "CommandRegistry.h"

//std::unordered_map<std::string, std::unique_ptr<CommandFactory>> CommandRegistry::factories;

CommandRegistry& CommandRegistry::getInstance()
{
    static CommandRegistry instance;
    return instance;
}

void CommandRegistry::registerCommand(const std::string& name, std::unique_ptr<CommandFactory> factory)
{
    getInstance().factories[name] = std::move(factory);
}

std::unique_ptr<Command> CommandRegistry::createCommand(const std::vector<Token>& tokens)
{   
    auto& map = getInstance().factories;
    auto it = map.find(tokens[0].getText());
    std::cout << "Started creating " + tokens[0].getText() + " command" << std::endl;
    return it->second->create(tokens);
}

void CommandRegistry::debugPrint()
{
    std::cout << "OC of all commands: " << std::endl;
    for (const auto& pair : factories) {
        std::cout << pair.first << std::endl;
    }
}

void CommandRegistry::populate()
{
    CommandRegistry::getInstance().registerCommand("echo", std::make_unique<TemplateCommandFactory<EchoCommand>>());
    CommandRegistry::getInstance().registerCommand("date", std::make_unique<TemplateCommandFactory<DateCommand>>());
    CommandRegistry::getInstance().registerCommand("time", std::make_unique<TemplateCommandFactory<TimeCommand>>());
    CommandRegistry::getInstance().registerCommand("touch", std::make_unique<TemplateCommandFactory<TouchCommand>>());
    CommandRegistry::getInstance().registerCommand("wc", std::make_unique<TemplateCommandFactory<WcCommand>>());
    CommandRegistry::getInstance().registerCommand("prompt", std::make_unique<TemplateCommandFactory<PromptCommand>>());
    CommandRegistry::getInstance().registerCommand("truncate", std::make_unique<TemplateCommandFactory<TruncateCommand>>());
    CommandRegistry::getInstance().registerCommand("rm", std::make_unique<TemplateCommandFactory<RmCommand>>());
    CommandRegistry::getInstance().registerCommand("batch", std::make_unique<TemplateCommandFactory<BatchCommand>>());
    CommandRegistry::getInstance().registerCommand("head", std::make_unique<TemplateCommandFactory<HeadCommand>>());
}
