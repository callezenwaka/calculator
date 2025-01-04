#include "calculator.h"
#include "utils.h"
#include <iostream>
#include <string>

using namespace calc;
using namespace calc::utils;

void handleMemoryOperations(Calculator& calc) {
    clearScreen();
    std::cout << "\nMemory Operations:\n";
    std::cout << "1. Memory Add (M+)\n";
    std::cout << "2. Memory Subtract (M-)\n";
    std::cout << "3. Memory Recall (MR)\n";
    std::cout << "4. Memory Clear (MC)\n";
    std::cout << "0. Back to main menu\n";
    
    char choice = getInput("Enter choice: ")[0];
    double value;
    
    switch (choice) {
        case '1':
            value = std::stod(getInput("Enter value to add to memory: "));
            calc.memoryAdd(value);
            break;
        case '2':
            value = std::stod(getInput("Enter value to subtract from memory: "));
            calc.memorySubtract(value);
            break;
        case '3':
            std::cout << "Memory value: " << calc.memoryRecall() << std::endl;
            break;
        case '4':
            calc.memoryClear();
            std::cout << "Memory cleared." << std::endl;
            break;
    }
    pauseScreen();
}

int main() {
    Calculator calc;
    std::string input;
    
    while (true) {
        clearScreen();
        calc.displayMenu();
        input = getInput("");
        
        if (input.empty()) continue;
        char choice = input[0];
        
        if (choice == '0') break;
        
        try {
            if (choice == 'M' || choice == 'm') {
                handleMemoryOperations(calc);
                continue;
            }
            
            double num1, num2;
            switch (choice) {
                case '1': // Addition
                    num1 = std::stod(getInput("Enter first number: "));
                    num2 = std::stod(getInput("Enter second number: "));
                    std::cout << "Result: " << calc.add(num1, num2) << std::endl;
                    break;
                    
                case '2': // Subtraction
                    num1 = std::stod(getInput("Enter first number: "));
                    num2 = std::stod(getInput("Enter second number: "));
                    std::cout << "Result: " << calc.subtract(num1, num2) << std::endl;
                    break;
                    
                case '3': // Multiplication
                    num1 = std::stod(getInput("Enter first number: "));
                    num2 = std::stod(getInput("Enter second number: "));
                    std::cout << "Result: " << calc.multiply(num1, num2) << std::endl;
                    break;
                    
                case '4': // Division
                    num1 = std::stod(getInput("Enter first number: "));
                    num2 = std::stod(getInput("Enter second number: "));
                    std::cout << "Result: " << calc.divide(num1, num2) << std::endl;
                    break;
                    
                case '5': // Square Root
                    num1 = std::stod(getInput("Enter number: "));
                    std::cout << "Result: " << calc.square_root(num1) << std::endl;
                    break;
                    
                case '6': // Power
                    num1 = std::stod(getInput("Enter base: "));
                    num2 = std::stod(getInput("Enter exponent: "));
                    std::cout << "Result: " << calc.power(num1, num2) << std::endl;
                    break;
                    
                case '7': // Sine
                    num1 = std::stod(getInput("Enter angle in degrees: "));
                    std::cout << "Result: " << calc.sine(num1) << std::endl;
                    break;
                    
                case '8': // Cosine
                    num1 = std::stod(getInput("Enter angle in degrees: "));
                    std::cout << "Result: " << calc.cosine(num1) << std::endl;
                    break;
                    
                case '9': // Tangent
                    num1 = std::stod(getInput("Enter angle in degrees: "));
                    std::cout << "Result: " << calc.tangent(num1) << std::endl;
                    break;
                    
                default:
                    displayError("Invalid choice!");
                    continue;
            }
        }
        catch (const std::exception& e) {
            displayError(e.what());
        }
        
        pauseScreen();
    }
    
    std::cout << "\nThank you for using the calculator!\n";
    return 0;
}