#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"
#include <stdexcept>

TEST_CASE("Проверка validateExpression") {
    CHECK(validateExpression("2+3"));
    CHECK(validateExpression("1.5*2"));
    CHECK_FALSE(validateExpression("2+3#"));
    CHECK_FALSE(validateExpression("hello"));
}

TEST_CASE("Проверка validateOperator") {
    CHECK(validateOperator('+'));
    CHECK(validateOperator('-'));
    CHECK(validateOperator('*'));
    CHECK(validateOperator('/'));
    CHECK(validateOperator('^'));
    CHECK_FALSE(validateOperator('%'));
    CHECK_FALSE(validateOperator('a'));
}

TEST_CASE("Проверка performOperation") {
    CHECK(performOperation(3, 2, '+') == 5);
    CHECK(performOperation(3, 2, '-') == 1);
    CHECK(performOperation(3, 2, '*') == 6);
    CHECK(performOperation(3, 2, '/') == 1.5);
    CHECK_THROWS_AS(performOperation(3, 0, '/'), std::runtime_error);
    CHECK(performOperation(2, 3, '^') == 8);
    CHECK_THROWS_AS(performOperation(3, 2, '%'), std::invalid_argument);
}

TEST_CASE("Проверка calculate") {
    CHECK(calculate("3+2^2") == 7);
    CHECK(calculate("3--2^2") == -1);
    CHECK(calculate("10-5*2") == 0);
    CHECK(calculate("2^3+4") == 12);
    CHECK(calculate("3/0.5") == 6);
    CHECK_THROWS_AS(calculate("3+2*"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("3//2"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("2^"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("3+2/0"), std::runtime_error);
}

TEST_CASE("Проверка некорректных выражений") {
    CHECK_THROWS_AS(calculate("3+2++4"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("3---2"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("3+2#4"), std::invalid_argument);
    CHECK_THROWS_AS(calculate("3.5.6+2"), std::invalid_argument);
}