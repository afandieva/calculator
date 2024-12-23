#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"
#include <stdexcept>

TEST_CASE("Проверка validateExpression") {
    CHECK(validateExpression("5*4"));
    CHECK(validateExpression("7.2+3"));
    CHECK_FALSE(validateExpression("4*5#"));
    CHECK_FALSE(validateExpression("invalid"));
}

TEST_CASE("Проверка validateOperator") {
    CHECK(validateOperator('+'));
    CHECK(validateOperator('-'));
    CHECK(validateOperator('/'));
    CHECK(validateOperator('*'));
    CHECK(validateOperator('^'));
    CHECK_FALSE(validateOperator('&'));
    CHECK_FALSE(validateOperator('z'));
}

TEST_CASE("Проверка performOperation") {
    CHECK(performOperation(5, 2, '+') == 7);
    CHECK(performOperation(8, 2, '-') == 6);
    CHECK(performOperation(6, 3, '*') == 18);
    CHECK(performOperation(9, 3, '/') == 3);
    CHECK(performOperation(3, 4, '^') == 81);
    CHECK_THROWS_AS(performOperation(5, 0, '/'), std::runtime_error);
    CHECK_THROWS_AS(performOperation(7, 3, '%'), std::invalid_argument);
}

TEST_CASE("Проверка calculate") {
    CHECK(calculate("4+3^2") == 13);
    CHECK(calculate("8--2^3") == -4);
    CHECK(calculate("12-6*2") == 0);
    CHECK(calculate("3^2+5") == 14);
    CHECK(calculate("6/0.25") == 24);
    CHECK_THROWS_AS(calculate("2+3*"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("4//3"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("5^"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("4+3/0"), std::runtime_error);
}

TEST_CASE("Проверка некорректных выражений") {
    CHECK_THROWS_AS(calculate("5+4++3"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("4---3"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("7*2#5"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("3.1.2+4"), std::invalid_argument);
}
