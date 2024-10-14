#pragma once

#include "Token.hpp"

namespace ds {

class Tokenizer {
public:
  explicit Tokenizer(const std::string &code) : m_beg(code.begin()) {}

  /**
   * Next token
   */
  Token next() {
    while (isspace(peek()))
      forward();
    if (isdigit(peek())) {
      return number();
    } else if ('(' == peek()) {
      return atom(Token::Kind::LeftParen);
    } else if (')' == peek()) {
      return atom(Token::Kind::RightParen);
    } else if ('+' == peek()) {
      return atom(Token::Kind::Plus);
    } else if ('-' == peek()) {
      return atom(Token::Kind::Minus);
    } else if ('*' == peek()) {
      return atom(Token::Kind::Asterisk);
    } else if ('\0' == peek()) {
      return Token(Token::Kind::End, m_beg, 1);
    } else {
      return atom(Token::Kind::Unexpected);
    }
  }

private:
  /**
   * A sequence of digits is a number token
   */
  Token number() {
    std::string::const_iterator start = m_beg;
    forward();
    while (isdigit(peek()))
      forward();
    return Token(Token::Kind::Number, start, m_beg);
  }

  Token atom(Token::Kind kind) {
    auto copy = m_beg;
    ++m_beg;
    return Token(kind, std::move(copy), 1); 
  }

  char peek() const { return *m_beg; }
  void forward() { ++m_beg; }

  std::string::const_iterator m_beg{};
};

} // namespace ds