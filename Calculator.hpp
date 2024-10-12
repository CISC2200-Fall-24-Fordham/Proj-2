#pragma once

#include "BigInt.hpp"
#include "Token.hpp"
#include <stack>

namespace ds {

class Calculator {
public:
  static BigInt calculate(std::stack<ds::Token> &postfixStk);
};

} // namespace ds