#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

namespace calc {

class Calculator {
private:
    double currentResult;
    double memory;  // For memory operations

public:
    Calculator();
    
    // Basic operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    
    // Advanced operations
    double square_root(double a);
    double power(double base, double exponent);
    double sine(double angle);
    double cosine(double angle);
    double tangent(double angle);
    
    // Memory operations
    void memoryAdd(double value);
    void memorySubtract(double value);
    void memoryClear();
    double memoryRecall() const;
    
    // Utility functions
    void displayMenu() const;
    double getCurrentResult() const;
    void setCurrentResult(double result);
};

} // namespace calc

#endif // CALCULATOR_H