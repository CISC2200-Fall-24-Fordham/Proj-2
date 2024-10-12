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

ds::BigInt::BigInt(std::string str)
{
  std::transform(str.begin(), str.end(), std::back_inserter(digits),
                 [](char c) { return c - '0'; });
}

void ds::BigInt::output()
{
  std::cout << *this << std::endl;
}

void ds::BigInt::add(const BigInt& a, const BigInt& b, BigInt& result) const
{
  int carry = 0;
  int i = a.digits.size() - 1;
  int j = b.digits.size() - 1;
  while (i >= 0 || j >= 0)
  {
    int sum = carry;
    if (i >= 0)
    {
      sum += a.digits[i];
      i--;
    }
    if (j >= 0)
    {
      sum += b.digits[j];
      j--;
    }
    carry = sum / 10;
    result.digits.insert(result.digits.begin(), sum % 10);
  }
  if (carry)
  {
    result.digits.insert(result.digits.begin(), carry);
  }
}

/**
  * @brief Subtract two BigInts
  * @param a the first BigInt
  * @param b the second BigInt
  * @param result the result of the subtraction
  *
  * @pre a >= b
  */
void ds::BigInt::subtract(const BigInt& a, const BigInt& b, BigInt& result) const
{
  int borrow = 0;
  int i = a.digits.size() - 1;
  int j = b.digits.size() - 1;
  while (i >= 0 || j >= 0)
  {
    int diff = borrow;
    if (i >= 0)
      diff += a.digits[i--];
    if (j >= 0)
      diff -= b.digits[j--];
    if (diff < 0)
    {
      borrow = -1;
      diff += 10;
    }
    else
      borrow = 0;

    result.digits.insert(result.digits.begin(), diff);
  }

  while(result.digits[0] == 0 && result.digits.size() > 1)
  {
    result.digits.erase(result.digits.begin());
  }
}

ds::BigInt ds::BigInt::operator+(const BigInt& other) const
{
  BigInt result;
  BigInt::add(*this, other, result);
  return result;
}

ds::BigInt ds::BigInt::operator-(const BigInt& other) const
{
  BigInt result;
  if (*this >= other)
  {
    BigInt::subtract(*this, other, result);
  }
  else
  {
    BigInt::subtract(other, *this, result);
  }
  return result;
}

bool ds::BigInt::operator>=(const BigInt& other) const
{
  if (digits.size() > other.digits.size())
  {
    return true;
  }
  else if (digits.size() < other.digits.size())
  {
    return false;
  }
  else
  {
    for (unsigned i = 0; i < digits.size(); i++)
    {
      if (digits[i] > other.digits[i])
      {
        return true;
      }
      else if (digits[i] < other.digits[i])
      {
        return false;
      }
    }
    return true;
  }
}

