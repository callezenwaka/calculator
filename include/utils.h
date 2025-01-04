#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace calc::utils {
    bool isValidNumber(const std::string& str);
    bool isValidOperation(char op);
    void clearScreen();
    void pauseScreen();
    void displayError(const std::string& message);
    std::string getInput(const std::string& prompt);
} // namespace calc::utils

#endif // UTILS_H