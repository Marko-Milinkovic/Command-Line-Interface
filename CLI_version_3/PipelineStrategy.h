#pragma once
#include "OutputStrategy.h"

class PipelineStrategy : public InputStrategy, public OutputStrategy {

    std::stringstream stream;

public:
    // InputStrategy implementation
    std::istream& getInStream() override {
        return stream;
    }

    // OutputStrategy implementation
    std::ostream& getOutStream() override {
        return stream;
    }
};