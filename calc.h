#ifndef CALC_H
#define CALC_H

#include <string>
#include <stdexcept>

double calc(const std::string& expr);
bool validExpr(const std::string& input);
bool isOp(char c);
double operate(double a, double b, char op);

#endif // CALC_H
