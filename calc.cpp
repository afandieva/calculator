#include "calc.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <cctype>

bool validateExpression(const std::string& input) {
    for (char c : input) {
        if (!(std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '.' || c == ' ')) {
            return false;
        }
    }
    return true;
}

bool validateOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

double performOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Division by zero");
            }
            return a / b;
        case '^': return std::pow(a, b);
        default: throw std::invalid_argument("Invalid operator");
    }
}

double calculate(const std::string& expression) {
    std::vector<double> numbers;
    std::vector<char> operators;
    std::string currentNumber;

    for (char currentChar : expression) {
        if (std::isdigit(currentChar) || currentChar == '.') {
            currentNumber += currentChar;
        } else {
            if (!currentNumber.empty()) {
                numbers.push_back(std::stod(currentNumber));
                currentNumber.clear();
            }

            if (validateOperator(currentChar)) {
                operators.push_back(currentChar);
            } else if (!std::isspace(currentChar)) {
                throw std::invalid_argument("Invalid character in expression");
            }
        }
    }

    if (!currentNumber.empty()) {
        numbers.push_back(std::stod(currentNumber));
    }

    if (numbers.size() != operators.size() + 1) {
        throw std::invalid_argument("Mismatched numbers and operators");
    }

    for (size_t i = 0; i < operators.size(); ++i) {
        if (operators[i] == '^') {
            numbers[i] = performOperation(numbers[i], numbers[i + 1], operators[i]);
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            --i;
        }
    }

    for (size_t i = 0; i < operators.size(); ++i) {
        if (operators[i] == '*' || operators[i] == '/') {
            numbers[i] = performOperation(numbers[i], numbers[i + 1], operators[i]);
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            --i;
        }
    }

    for (size_t i = 0; i < operators.size(); ++i) {
        numbers[i] = performOperation(numbers[i], numbers[i + 1], operators[i]);
        numbers.erase(numbers.begin() + i + 1);
        operators.erase(operators.begin() + i);
        --i;
    }

    return numbers[0];
}