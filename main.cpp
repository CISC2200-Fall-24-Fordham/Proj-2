#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BigInt.hpp"
#include "Calculator.hpp"
#include "Transformer.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
  std::string inputExpr;
  std::getline(std::cin, inputExpr);
  std::stack<ds::Token> postfixStk = ds::InfixToPostfixTransformer::transform(inputExpr);
  ds::BigInt res = ds::Calculator::calculate(postfixStk);
  res.output();
}
