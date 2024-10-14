#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Calculator.hpp"
#include "Transformer.hpp"
#include "doctest.h"
#include <sstream>
#include <string>

TEST_CASE("InfixToPostfix") {
  std::string inputExpr, result;
  SUBCASE("Case1")
  {
    inputExpr = "456 + (1123 - 1) + 1";
    result = "Plus(+) Number(1) Plus(+) Minus(-) Number(1) Number(1123) Number(456) ";
  }
  SUBCASE("Case2")
  {
    inputExpr = "456 - 1123 + 3452 * 234 - 1234543 - 3425236 + 234234 - 4536456";
    result = "Minus(-) Number(4536456) Plus(+) Number(234234) Minus(-) Number(3425236)"
             " Minus(-) Number(1234543) Plus(+) Asterisk(*) Number(234) Number(3452) Minus(-)"
             " Number(1123) Number(456) ";
  }

  std::stack<ds::Token> postfixStk = ds::InfixToPostfixTransformer::transform(inputExpr);

  std::stringstream ss1;
  std::stack<ds::Token> postfixStkCopy = postfixStk;
  while (!postfixStkCopy.empty()) {
    ds::Token top = postfixStkCopy.top();
    postfixStkCopy.pop();
    ss1 << top << " ";
  }
  REQUIRE(ss1.str() == result);
}

TEST_CASE("Calculator") {
  std::string inputExpr, result;
  SUBCASE("Case1")
  {
    inputExpr = "456 + (1123 - 1) + 1";
    result = "1579";
  }
  SUBCASE("Case2")
  {
    inputExpr = "234 * 3452";
    result = "807768";
  }
  SUBCASE("Case3") {
    inputExpr = "456 - 1123 + 3452 * 234 - 1234543 - 3425236 + 234234 - 4536456";
    result = "1303094";
  }
  std::stack<ds::Token> postfixStk = ds::InfixToPostfixTransformer::transform(inputExpr);
  ds::BigInt res = ds::Calculator::calculate(postfixStk);
  std::stringstream ss2;
  ss2 << res;
  REQUIRE(ss2.str() == result);
}