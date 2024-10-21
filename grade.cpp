#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Calculator.hpp"
#include "Transformer.hpp"
#include <algorithm>
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string printTokenStack(std::stack<ds::Token> stk) {
  std::stringstream ss;
  while (!stk.empty()) {
    ss << stk.top() << " ";
    stk.pop();
  }
  return ss.str();
}

TEST_CASE("InfixToPostfix") {
  std::string code, res;
  SUBCASE("Case1") {
    code = "456 - 1123 + 3452 - 234 - 1234543 - 3425236 + 234234 - 4536456";
    res = "Minus(-) Number(4536456) Plus(+) Number(234234) Minus(-) "
          "Number(3425236) Minus(-) Number(1234543) Minus(-) Number(234) "
          "Plus(+) Number(3452) Minus(-) Number(1123) Number(456) ";
  }
  SUBCASE("Case2") {
    code = "(0 - 43253265987902374 - 2345907 + 329078) + 0";
    res = "Plus(+) Number(0) Plus(+) Number(329078) Minus(-) Number(2345907) "
          "Minus(-) Number(43253265987902374) Number(0) ";
  }
  SUBCASE("Case3") {
    code = "(9783245 + 435) - 2349507845 - (9087345 - 12349087)";
    res = "Minus(-) Minus(-) Number(12349087) Number(9087345) Minus(-) "
          "Number(2349507845) Plus(+) Number(435) Number(9783245) ";
  }
  SUBCASE("Case4") {
    code = "2349587938475 + (123489709845 - 1234789832417098) - (3928765435 - "
           "987991234987)";
    res = "Minus(-) Minus(-) Number(987991234987) Number(3928765435) Plus(+) "
          "Minus(-) Number(1234789832417098) Number(123489709845) "
          "Number(2349587938475) ";
  }
  SUBCASE("Case5") {
    code = "(986812 - ((78968345 - 87682314 + 2137896) + 324978)) - "
           "3249870980456 + (3294057890 + (987073425 - 32452345)) + 987394027";
    res = "Plus(+) Number(987394027) Plus(+) Plus(+) Minus(-) Number(32452345) "
          "Number(987073425) Number(3294057890) Minus(-) Number(3249870980456) "
          "Minus(-) Plus(+) Number(324978) Plus(+) Number(2137896) Minus(-) "
          "Number(87682314) Number(78968345) Number(986812) ";
  }

  REQUIRE(printTokenStack(ds::InfixToPostfixTransformer::transform(code)) ==
          res);
}

TEST_CASE("Calculator") {
  std::string code, res;
  SUBCASE("Case1") {
    code = "456 - 1123 + 3452 - 234 - 1234543 - 3425236 + 234234 - 4536456";
    res = "2107644";
  }
  SUBCASE("Case2") {
    code = "(0 - 43253265987902374 - 2345907 + 329078) + 0";
    res = "43253265985885545";
  }
  SUBCASE("Case3") {
    code = "(9783245 + 435) - 2349507845 - (9087345 - 12349087)";
    res = "2336462423";
  }
  SUBCASE("Case4") {
    code = "2349587938475 + (123489709845 - 1234789832417098) - (3928765435 - "
           "987991234987)";
    res = "1236031868176176";
  }
  SUBCASE("Case5") {
    code = "(986812 - ((78968345 - 87682314 + 2137896) + 324978)) - "
           "3249870980456 + (3294057890 + (987073425 - 32452345)) + 987394027";
    res = "3255096863422";
  }

  auto stk = ds::InfixToPostfixTransformer::transform(code);
  std::stringstream ss;
  ss << ds::Calculator::calculate(stk);
  REQUIRE(ss.str() == res);
}

TEST_CASE("Extra") {
  std::string code, res;
  SUBCASE("Case1") {
    code = "456 - 1123 + 3452 * 234 - 1234543 - 3425236 + 234234 - 4536456";
    res = "1303094";
  }
  SUBCASE("Case2") {
    code = "(0 - 43253265987902374 - 2345907 + 329078) * 0";
    res = "0";
  }
  SUBCASE("Case3") {
    code = "(9783245 + 435) * 2349507845 - (9087345 * 12349087)";
    res = "22874612498965585";
  }
  SUBCASE("Case4") {
    code = "2349587938475 + (123489709845 - 1234789832417098) * (3928765435 - "
           "987991234987)";
    res = "1214988810277237702149999131";
  }
  SUBCASE("Case5") {
    code = "(986812 - ((78968345 * 87682314 + 2137896) + 324978)) - "
           "3249870980456 * (3294057890 + (987073425 - 32452345)) + 987394027";
    res = "13807651565750451777955";
  }

  auto stk = ds::InfixToPostfixTransformer::transform(code);
  std::stringstream ss;
  ss << ds::Calculator::calculate(stk);
  REQUIRE(ss.str() == res);
}
