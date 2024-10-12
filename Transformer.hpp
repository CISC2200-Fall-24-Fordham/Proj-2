#pragma once

#include "Tokenizer.hpp"
#include <stack>
#include <vector>

namespace ds {

class InfixToPostfixTransformer {
public:
  /**
   * Helper method to do the transformation.
   */
  static std::stack<Token> transform(const std::string &code) {
    std::vector<Token> infix = tokenStreamToList(code);
    return infixToPostfix(infix);
  }

private:
  /**
   * Convert stream of tokens to a list.
   */
  static std::vector<Token> tokenStreamToList(const std::string &code) {
    Tokenizer lexer(code);
    std::vector<Token> res;
    for (Token token = lexer.next();
         !token.is_one_of(Token::Kind::End, Token::Kind::Unexpected);
         token = lexer.next())
      res.push_back(token);
    return res;
  }

  static std::stack<Token> infixToPostfix(const std::vector<Token> &infix);
};

} // namespace ds