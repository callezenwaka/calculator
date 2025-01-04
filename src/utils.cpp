#include "utils.h"
#include <iostream>
#include <cctype>
#include <limits>

namespace calc::utils {

bool isValidNumber(const std::string& str) {
    try {
        size_t pos = 0;
        std::stod(str, &pos);
        return pos == str.length();
    } catch (...) {
        return false;
    }
}

bool isValidOperation(char op) {
    return (op == '1' || op == '2' || op == '3' || op == '4' ||
            op == '5' || op == '6' || op == '7' || op == '8' ||
            op == '9' || op == '0' || op == 'M' || op == 'm');
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void displayError(const std::string& message) {
    std::cerr << "\nError: " << message << std::endl;
    pauseScreen();
}

std::string getInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

} // namespace calc::utils