#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include "doctest.h"



// Функция для проверки приоритета оператора
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Применение оператора к двум числам
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::invalid_argument("Деление на ноль");
            return a / b;
        case '^': return std::pow(a, b);
        default: throw std::invalid_argument("Неизвестный оператор");
    }
}

// Проверка корректности выражения
bool isValidExpression(const std::string& expression) {
    if (expression.empty()) return false;

    bool expectingNumber = true;
    bool hasValidChar = false;

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (std::isspace(c)) continue;

        if (expectingNumber) {
            // Разрешаем числа и знак перед числами
            if (std::isdigit(c) || c == '.' || (c == '-' && (i == 0 || !std::isdigit(expression[i - 1])))) {
                hasValidChar = true;
                if (c == '-') ++i; // Пропускаем знак перед числом
                while (i < expression.size() && (std::isdigit(expression[i]) || expression[i] == '.')) {
                    ++i;
                }
                --i;
                expectingNumber = false;
                continue;
            }
            return false;
        } else {
            // Разрешаем только операторы
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                expectingNumber = true;
                continue;
            }
            return false;
        }
    }

    return hasValidChar && !expectingNumber;
}


double evaluateExpression(const std::string& expression) {
    std::stack<double> values;
    std::stack<char> ops;

    for (size_t i = 0; i < expression.size(); ++i) {
        if (std::isspace(expression[i])) continue;

        if (std::isdigit(expression[i]) || expression[i] == '.' || (expression[i] == '-' && (i == 0 || !std::isdigit(expression[i - 1])))) {
            std::string num;
            if (expression[i] == '-') num += expression[i++];
            while (i < expression.size() && (std::isdigit(expression[i]) || expression[i] == '.')) {
                num += expression[i++];
            }
            values.push(std::stod(num));
            --i;
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(expression[i]);
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}

int main() {
    std::string input;
    std::cout << "Введите математическое выражение без скобок (или 'exit' для выхода): ";
    while (std::getline(std::cin, input)) {
        if (input == "exit") break;

        if (!isValidExpression(input)) {
            std::cout << "Некорректное выражение. Попробуйте снова.\n";
            continue;
        }

        try {
            double result = evaluateExpression(input);
            std::cout << "Результат: " << result << '\n';
        } catch (const std::invalid_argument& e) {
            std::cout << "Ошибка: " << e.what() << '\n';
        } catch (...) {
            std::cout << "Неизвестная ошибка.\n";
        }
        std::cout << "Введите математическое выражение без скобок (или 'exit' для выхода): ";
    }
    return 0;
}


