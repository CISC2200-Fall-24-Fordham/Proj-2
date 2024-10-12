#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BigInt.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
// If you want to get doctest here...
// #include <doctest.h>

using namespace std;

#define SIZE 10

int main()
{
  string input1,input2, op;

  cin >> op;
  cin >> input1;
  cin >> input2;

  ds::BigInt a(input1);
  ds::BigInt b(input2);

  if (op=="add")
  {
  	ds::BigInt r = a + b;
  	r.output();
  }
  else if (op=="subtract")
  {
	//assume a>=b
  	ds::BigInt r2 = a - b;
  	r2.output();
   }

}