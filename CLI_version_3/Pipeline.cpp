#include "Pipeline.h"


void Pipeline::append(std::unique_ptr<Command> cmd)
{
    auto newNode = std::make_unique<Pipeline::Node>(std::move(cmd));

    std::cout << "Command " + newNode->info->getOpcode().getText() + " added to pipeline" << std::endl;

    if (!head) {
        head = std::move(newNode);
        tail = head.get();
        head.get()->info->setFirstInPipeline(true);
        head.get()->info->setLastInPipeline(true);
    }
    else {
        tail->next = std::move(newNode);
        tail->info->setLastInPipeline(false);
        tail = tail->next.get();
        tail->info->setLastInPipeline(true);
    }
    
    ++size;

}

void Pipeline::executeAll()
{
    Pipeline::Node* current = head.get(); 
    while (current) {
        current->info->execute();
        current = current->next.get();
    }
    this->clear();
    this->size = 0;
    std::cout << "Pipeline executed" << std::endl;
}

std::vector<const Command*> Pipeline::getCommands() const
{
    std::vector<const Command*> commands;
    const Node* current = head.get();
    while (current != nullptr) {
        commands.push_back(current->info.get());
        current = current->next.get();
    }
    return commands;
}

void Pipeline::configure()
{       
    Pipeline::Node* temp1 = head.get();
    Pipeline::Node* temp2 = temp1->next.get();

    while (temp2) {

        auto sharedStream = std::make_shared<PipelineStrategy>();

        temp1->info->setOutput(std::static_pointer_cast<OutputStrategy>(sharedStream));
        temp2->info->setInput(std::static_pointer_cast<InputStrategy>(sharedStream));

        temp1->info->setIsInPipeline(true);
        temp2->info->setIsInPipeline(true);

        temp1 = temp2;
        temp2 = temp2->next.get();
    }

    std::cout << "Pipeline configured" << std::endl;

}

void Pipeline::debugPrint()
{
    Pipeline::Node* current = head.get();
    std::string line = "PIPELINE [ ";
    while (current) {
        if (current->info->getFirstInPipeline() == true) { 
            std::cout << "First in pipeline: " + current->info->getOpcode().getText() << std::endl;
        }
        if (current->info->getLastInPipeline() == true) {
            std::cout << "Last in pipeline: " + current->info->getOpcode().getText() << std::endl;
        }
        line += current->info->getOpcode().getText() + " ";
        current = current->next.get();
    }
    line += "]";
    std::cout << line << std::endl;
}


