#include <gtest/gtest.h>
#include "calculator.h"
#include <cmath>

using namespace calc;

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;
    
    // Define tolerance for floating-point comparisons
    const double EPSILON = 1e-6;
};

// Basic Operations Tests
TEST_F(CalculatorTest, Addition) {
    EXPECT_DOUBLE_EQ(calc.add(2, 3), 5);
    EXPECT_DOUBLE_EQ(calc.add(-2, 3), 1);
    EXPECT_DOUBLE_EQ(calc.add(0, 0), 0);
}

TEST_F(CalculatorTest, Subtraction) {
    EXPECT_DOUBLE_EQ(calc.subtract(5, 3), 2);
    EXPECT_DOUBLE_EQ(calc.subtract(-2, 3), -5);
    EXPECT_DOUBLE_EQ(calc.subtract(0, 0), 0);
}

TEST_F(CalculatorTest, Multiplication) {
    EXPECT_DOUBLE_EQ(calc.multiply(2, 3), 6);
    EXPECT_DOUBLE_EQ(calc.multiply(-2, 3), -6);
    EXPECT_DOUBLE_EQ(calc.multiply(0, 5), 0);
}

TEST_F(CalculatorTest, Division) {
    EXPECT_DOUBLE_EQ(calc.divide(6, 2), 3);
    EXPECT_DOUBLE_EQ(calc.divide(-6, 2), -3);
    EXPECT_THROW(calc.divide(5, 0), std::runtime_error);
}

// Advanced Operations Tests
TEST_F(CalculatorTest, SquareRoot) {
    EXPECT_DOUBLE_EQ(calc.square_root(16), 4);
    EXPECT_DOUBLE_EQ(calc.square_root(0), 0);
    EXPECT_THROW(calc.square_root(-1), std::runtime_error);
}

TEST_F(CalculatorTest, Power) {
    EXPECT_DOUBLE_EQ(calc.power(2, 3), 8);
    EXPECT_DOUBLE_EQ(calc.power(2, 0), 1);
    EXPECT_DOUBLE_EQ(calc.power(2, -1), 0.5);
}

TEST_F(CalculatorTest, Trigonometry) {
    // Test sine
    EXPECT_NEAR(calc.sine(0), 0, EPSILON);
    EXPECT_NEAR(calc.sine(90), 1, EPSILON);
    EXPECT_NEAR(calc.sine(180), 0, EPSILON);
    
    // Test cosine
    EXPECT_NEAR(calc.cosine(0), 1, EPSILON);
    EXPECT_NEAR(calc.cosine(90), 0, EPSILON);
    EXPECT_NEAR(calc.cosine(180), -1, EPSILON);
    
    // Test tangent
    EXPECT_NEAR(calc.tangent(0), 0, EPSILON);
    EXPECT_NEAR(calc.tangent(45), 1, EPSILON);
}

// Memory Operations Tests
TEST_F(CalculatorTest, MemoryOperations) {
    // Test memory clear initial state
    EXPECT_DOUBLE_EQ(calc.memoryRecall(), 0);
    
    // Test memory add
    calc.memoryAdd(5);
    EXPECT_DOUBLE_EQ(calc.memoryRecall(), 5);
    
    // Test memory subtract
    calc.memorySubtract(3);
    EXPECT_DOUBLE_EQ(calc.memoryRecall(), 2);
    
    // Test memory clear
    calc.memoryClear();
    EXPECT_DOUBLE_EQ(calc.memoryRecall(), 0);
}

// Current Result Tests
TEST_F(CalculatorTest, CurrentResult) {
    calc.add(5, 3);
    EXPECT_DOUBLE_EQ(calc.getCurrentResult(), 8);
    
    calc.multiply(calc.getCurrentResult(), 2);
    EXPECT_DOUBLE_EQ(calc.getCurrentResult(), 16);
}

// Edge Cases Tests
TEST_F(CalculatorTest, EdgeCases) {
    // Test very large numbers
    EXPECT_NO_THROW(calc.add(1e308, 1e308));
    
    // Test very small numbers
    EXPECT_NEAR(calc.add(1e-308, 1e-308), 2e-308, EPSILON);
    
    // Test negative zero
    EXPECT_DOUBLE_EQ(calc.add(-0.0, 0.0), 0.0);
}

// Compound Operations Tests
TEST_F(CalculatorTest, CompoundOperations) {
    // Test a series of operations
    calc.setCurrentResult(0);
    calc.add(5, 3);        // Result: 8
    calc.multiply(calc.getCurrentResult(), 2);  // Result: 16
    calc.subtract(calc.getCurrentResult(), 6);  // Result: 10
    calc.divide(calc.getCurrentResult(), 2);    // Result: 5
    
    EXPECT_DOUBLE_EQ(calc.getCurrentResult(), 5);
}