#pragma once

#include <ostream>
#include <string>
#include <cassert>

namespace ds {

class Token {
public:
  enum class Kind {
    Number,
    LeftParen,
    RightParen,
    Plus,
    Minus,
    Asterisk,
    End,
    Unexpected
  };

  Kind kind{};
  std::string lexeme{};

  explicit Token(Kind k) : kind(k) {}

  Token(Kind k, const std::string &s) : kind(k), lexeme(s) {}

  Token(Kind k, std::string::const_iterator beg, size_t len)
      : kind(k), lexeme(beg, beg + len) {}

  Token(Kind k, std::string::const_iterator beg,
        std::string::const_iterator end)
      : kind(k), lexeme(beg, end) {}

  bool is(Kind k) const { return kind == k; }

  bool is_one_of(Kind k1, Kind k2) const { return is(k1) || is(k2); }

  template <typename... Ts> bool is_one_of(Kind k1, Kind k2, Ts... ks) const {
    return is(k1) || is_one_of(k2, ks...);
  }

  friend std::ostream &operator<<(std::ostream &os, const Token &token) {
    static const char *const names[]{
        "Number", "LeftParen", "RightParen", "Plus",
        "Minus",  "Asterisk",  "End",        "Unexpected",
    };
    return os << names[static_cast<int>(token.kind)] << "("
              << token.lexeme + ")";
  }

  // Need to support >= operator to compare precendence of operators
  // Paren > Asterisk > (Plus == Minus)
  bool operator>=(const Token &other) const {
    if (kind == Kind::LeftParen || kind == Kind::RightParen)
      return true;
    else if (other.kind == Kind::LeftParen || other.kind == Kind::RightParen)
      return false;
    if (kind == Kind::Asterisk)
      return true;
    else if (other.kind == Kind::Asterisk)
      return false;
    
    // Plus and Minus have the same precedence
    assert(kind == Kind::Plus || kind == Kind::Minus);
    assert(other.kind == Kind::Plus || other.kind == Kind::Minus);
    return true;
  }
};

} // namespace ds