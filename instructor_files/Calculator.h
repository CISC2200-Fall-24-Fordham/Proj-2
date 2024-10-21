#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "BigInt.h"
#include "Token.h"
#include <stack>

using namespace std;

namespace ds {

class Calculator {
public:
  static BigInt calculate(stack<Token> &postfixStk);
};

} // namespace ds

#endif // __CALCULATOR_H__