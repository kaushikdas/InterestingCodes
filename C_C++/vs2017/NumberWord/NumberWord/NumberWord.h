#ifndef __NUMBER_WORD
#define _NUMBER_WORD

#include <vector>
#include <sstream>
#include <iostream>

using uint64_t = unsigned long long;
using uint8_t = unsigned char;
using uint16_t = unsigned short;

namespace kd
{
  class NumberWord
  {
  public:
    NumberWord() = default;
    ~NumberWord() { nodes.clear(); };

    void setNumber(uint64_t n);

    std::string toString();
  private:
    class NumberNode
    {
    public:
      NumberNode() = default;
      NumberNode(uint16_t v, uint8_t p = 0) : _val{ v }, _pos{ p } { };
      ~NumberNode() { std::cout << "node clear" << std::endl; };

      std::string toString();

    private:
      uint8_t _pos;
      uint16_t _val;

      std::string _getWord3Digits(uint16_t x);

      std::string _getWord2Digits(uint8_t x);

      std::string _getWord1Digit(uint8_t x);
    };

    uint64_t _n;
    std::vector<NumberNode*> nodes;

    const uint64_t NUM_LIMIT = 1000000000000000000;
  };
}

// for std::cout
std::ostream& operator<<(std::ostream& os, kd::NumberWord nw);
#endif // !__NUMBER_WORD
