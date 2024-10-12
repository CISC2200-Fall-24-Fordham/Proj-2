#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BigInt.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
  ds::BigInt a("1234567890123");
  ds::BigInt b("1567890123");

  a.output(); //this should display a's value: 1234567890123

  ds::BigInt r = a + b;
  r.output();  //This should display 1236135780246

  ds::BigInt r2 = b - a;
  r2.output(); //This should display 123300000000

}
