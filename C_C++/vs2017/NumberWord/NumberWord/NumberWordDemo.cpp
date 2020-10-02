#include <cstdio>
#include "NumberWord.h"

int main(int argc, char const *argv[])
{
  //freopen("NumberWord.txt", "r", stdin);
  std::cout << "NUMBER WORD DEMO CLIENT" << std::endl;
  kd::NumberWord nw;

  int tc{};
  std::cin >> tc;
  for (int t = 0; t < tc; ++t)
  {
    uint64_t n{};
    std::cin >> n;
    nw.setNumber(n);
    std::cout << "Number is " << n << " (" << nw << ")" << std::endl;
  }
  return 0;
}

///:~

/*
>NumberWord.exe < ..\NumberWord\NumberWord.txt
NUMBER WORD DEMO CLIENT
Number is 3 (three)
Number is 47 (forty-seven)
Number is 73 (seventy-three)
Number is 1492 (one-thousand four-hundred ninty-two)
Number is 10012 (ten-thousand twelve)
Number is 100073 (one-hundred-thousand seventy-three)
Number is 1000000 (one-million)
Number is 1000000001 (one-billion one)
Number is 100000000000 (one-hundred-billion)
Number is 474142398123 (four-hundred seventy-four-billion one-hundred forty-two-million three-hundred ninty-eight-thousand one-hundred twenty-three)
Number is 1474142398007 (one-trillion four-hundred seventy-four-billion one-hundred forty-two-million three-hundred ninty-eight-thousand seven)
Number is 999000000000000 (nine-hundred ninty-nine-trillion)
Number is 999999999999999999 (nine-hundred ninty-nine-quadrillion nine-hundred ninty-nine-trillion nine-hundred ninty-nine-billion nine-hundred ninty-nine-million nine-hundred ninty-nine-thousand nine-hundred ninty-nine)
Number is 1000000000000000000 (ERROR: TOO BIG NUMBER)
*/