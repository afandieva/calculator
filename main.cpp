#include <iostream>
#include <string>
#include <algorithm>
#include "calc.h"

int main() {
    std::string expression;

    while (true) {
        std::cout << "Введите выражение (или напишите 'stop' для выхода): ";
        std::getline(std::cin, expression);

        if (expression == "stop") {
            break;
        }

        try {
            expression.erase(std::remove_if(expression.begin(), expression.end(), ::isspace), expression.end());

            if (!validateExpression(expression)) {
                throw std::invalid_argument("Некорректное выражение.");
            }

            double result = calculate(expression);
            std::cout << "Результат: " << result << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << "\n";
        }
    }

    return 0;
}


