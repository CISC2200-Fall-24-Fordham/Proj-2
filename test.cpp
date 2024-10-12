#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Calculator.hpp"
#include "Transformer.hpp"
#include "doctest.h"
#include <sstream>
#include <string>

TEST_CASE("All") {
  std::string inputExpr = "456 + (1123 - 1) + 1";

  std::stack<ds::Token> postfixStk = ds::InfixToPostfixTransformer::transform(inputExpr);

  std::stringstream ss1;
  std::stack<ds::Token> postfixStkCopy = postfixStk;
  while (!postfixStkCopy.empty()) {
    ds::Token top = postfixStkCopy.top();
    postfixStkCopy.pop();
    ss1 << top << " ";
  }
  REQUIRE(ss1.str() == "Plus(+) Number(1) Plus(+) Minus(-) "
                       "Number(1) Number(1123) Number(456) ");

  ds::BigInt res = ds::Calculator::calculate(postfixStk);
  std::stringstream ss2;
  ss2 << res;
  REQUIRE(ss2.str() == "1579");
}