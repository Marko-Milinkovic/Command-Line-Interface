#include "StringSplitter.h"

std::vector<std::string> StringSplitter::split(const std::string& input)
{
    std::vector<std::string> result;
    std::string buffer;

    for (char c : input) {
        if (c == '|' || c == '\n' || c == EOF) {
            result.push_back(buffer);
            buffer.clear();
        }
        else if (c == ' ' && buffer.empty()) {
            continue;
        }
        else {
            buffer += c;
        }
    }

    result.push_back(buffer);

    return result;
}
