#pragma once
#include "OutputStrategy.h"
#include "Tokenizer.h"

class IOBindingResolver {
public:

    struct IOContext {

        std::shared_ptr<InputStrategy> input;
        std::shared_ptr<OutputStrategy> output;

        /*
        IOContext() = default;
        IOContext(const IOContext&) = delete;
        IOContext& operator=(const IOContext&) = delete;

        IOContext(IOContext&&) = default;
        IOContext& operator=(IOContext&&) = default;
        */
    };

    std::unique_ptr<IOContext>resolve(const std::vector<Token>& tokens) const;

private:

    void inputSetter(const std::vector<Token>& tokens, IOContext& io) const;
    void outputSetter(const std::vector<Token>& tokens, IOContext& io) const;

};


