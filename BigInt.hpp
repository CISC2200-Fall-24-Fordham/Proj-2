#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

namespace ds
{
  class BigInt
  {
  public:
    BigInt() = default;
    explicit BigInt(std::string str);
    // Since we are not managing dynamic memory, we don't need the rule of three!
    void output();
    void add(const BigInt& a, const BigInt& b, BigInt& result) const;
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    // While this function strictly isn't required, it is helpful for `-` operator
    bool operator>=(const BigInt& other) const;
    // This operator is used in testing
    friend std::ostream& operator<<(std::ostream& os, const BigInt& d)
    {
      for (auto digit : d.digits)
      {
        os << digit;
      }
      return os;
    }
  private:
    void subtract(const BigInt& a, const BigInt& b, BigInt& result) const;
    std::vector<int> digits;
  };

}