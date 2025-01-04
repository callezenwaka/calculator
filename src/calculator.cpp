#include "calculator.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

namespace calc {

Calculator::Calculator() : currentResult(0), memory(0) {}

double Calculator::add(double a, double b) {
    currentResult = a + b;
    return currentResult;
}

double Calculator::subtract(double a, double b) {
    currentResult = a - b;
    return currentResult;
}

double Calculator::multiply(double a, double b) {
    currentResult = a * b;
    return currentResult;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero!");
    }
    currentResult = a / b;
    return currentResult;
}

double Calculator::square_root(double a) {
    if (a < 0) {
        throw std::runtime_error("Cannot calculate square root of negative number!");
    }
    currentResult = std::sqrt(a);
    return currentResult;
}

double Calculator::power(double base, double exponent) {
    currentResult = std::pow(base, exponent);
    return currentResult;
}

double Calculator::sine(double angle) {
    currentResult = std::sin(angle * M_PI / 180.0);
    return currentResult;
}

double Calculator::cosine(double angle) {
    currentResult = std::cos(angle * M_PI / 180.0);
    return currentResult;
}

double Calculator::tangent(double angle) {
    currentResult = std::tan(angle * M_PI / 180.0);
    return currentResult;
}

void Calculator::memoryAdd(double value) {
    memory += value;
}

void Calculator::memorySubtract(double value) {
    memory -= value;
}

void Calculator::memoryClear() {
    memory = 0;
}

double Calculator::memoryRecall() const {
    return memory;
}

void Calculator::displayMenu() const {
    std::cout << "\nCalculator Menu:\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Square Root (√)\n";
    std::cout << "6. Power (^)\n";
    std::cout << "7. Sine (sin)\n";
    std::cout << "8. Cosine (cos)\n";
    std::cout << "9. Tangent (tan)\n";
    std::cout << "M. Memory Operations\n";
    std::cout << "0. Exit\n";
    std::cout << "Current Result: " << currentResult << "\n";
    std::cout << "Memory: " << memory << "\n";
    std::cout << "Enter your choice: ";
}

double Calculator::getCurrentResult() const {
    return currentResult;
}

void Calculator::setCurrentResult(double result) {
    currentResult = result;
}

} // namespace calc