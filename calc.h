#ifndef CALC_H
#define CALC_H

#include <string>
#include <stdexcept>

double calculate(const std::string& expression);
bool validateExpression(const std::string& input);
bool validateOperator(char c);
double performOperation(double a, double b, char op);

#endif // CALC_H