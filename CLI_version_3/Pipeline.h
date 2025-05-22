#pragma once
#include "Command.h"
#include "PipelineStrategy.h"


class Pipeline {

public:

    Pipeline() = default;
    ~Pipeline() = default;

    void append(std::unique_ptr<Command> cmd);

    void executeAll();

    bool isEmpty() const {
        return head == nullptr;
    }

    void clear() {
        head.reset();
        tail = nullptr;
        size = 0;
    }

    int getSize() { return this->size; }

    std::vector<const Command*> getCommands() const;

    void configure();
    void debugPrint();

protected:

    struct Node {

        std::unique_ptr<Command> info;
        std::unique_ptr<Node> next;

        Node(std::unique_ptr<Command> cmd)
            : info(std::move(cmd)), next(nullptr) {}
    };

    std::unique_ptr<Node> head = nullptr;
    Node* tail = nullptr;
    int size = 0;
};
