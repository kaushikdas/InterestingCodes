#include "NumberWord.h"

using namespace kd;

std::string NumberWord::NumberNode::_getWord1Digit(uint8_t x)
{
  switch (x)
  {
  case 0: return "zero";
  case 1: return "one";
  case 2: return "two";
  case 3: return "three";
  case 4: return "four";
  case 5: return "five";
  case 6: return "six";
  case 7: return "seven";
  case 8: return "eight";
  case 9: return "nine";
  }

  // This should never come
  return "ERROR";
}

std::string NumberWord::NumberNode::_getWord2Digits(uint8_t x)
{
  if (x < 20)
  {
    switch (x)
    {
    case 10: return "ten";
    case 11: return "eleven";
    case 12: return "twelve";
    case 13: return "thirteen";
    case 14: return "forteen";
    case 15: return "fifteen";
    case 16: return "sixteen";
    case 17: return "seventeen";
    case 18: return "eighteen";
    case 19: return "nineteen";
    default:
    {
      // it should not come here
      return "ERROR";
    }
    }
  }

  // x >= 20
  std::string temp{ "" };
  switch (x / 10)
  {
  case 2:
    temp = "twenty"; break;
  case 3:
    temp = "thirty"; break;
  case 4:
    temp = "forty"; break;
  case 5:
    temp = "fifty"; break;
  case 6:
    temp = "sixty"; break;
  case 7:
    temp = "seventy"; break;
  case 8:
    temp = "eighty"; break;
  case 9:
    temp = "ninty"; break;
  default:
  {
    // it should not come here
    return "ERROR";
  }
  }

  uint8_t y{ static_cast<uint8_t>(x % 10) };
  if (y > 0)
  {
    temp += "-" + _getWord1Digit(y);
  }

  return temp;
}

std::string NumberWord::NumberNode::_getWord3Digits(uint16_t x)
{
  if (x < 10) return _getWord1Digit(static_cast<uint8_t>(x));
  if (x < 100) return _getWord2Digits(static_cast<uint8_t>(x));

  std::string temp{ "" };
  switch (x / 100)
  {
  case 1:
    temp = "one-hundred"; break;
  case 2:
    temp = "two-hundred"; break;
  case 3:
    temp = "three-hundred"; break;
  case 4:
    temp = "four-hundred"; break;
  case 5:
    temp = "five-hundred"; break;
  case 6:
    temp = "six-hundred"; break;
  case 7:
    temp = "seven-hundred"; break;
  case 8:
    temp = "eight-hundred"; break;
  case 9:
    temp = "nine-hundred"; break;
  default:
  {
    // it should not come here
    return "ERROR";
  }
  }

  uint8_t y{ static_cast<uint8_t>(x % 100) };
  if (y >= 10)
  {
    temp += " " + _getWord2Digits(y);
  }
  else if (y > 0)
  {
    temp += " " + _getWord1Digit(static_cast<uint8_t>(y));
  }

  return temp;
}


std::string NumberWord::NumberNode::toString()
{
  std::string temp = "";

  if (_val > 0) {
    temp = _getWord3Digits(_val);
    switch (_pos)
    {
    case 0: break;
    case 3: temp += "-thousand"; break;
    case 6: temp += "-million"; break;
    case 9: temp += "-billion"; break;
    case 12: temp += "-trillion"; break;
    case 15: temp += "-quadrillion"; break;
    default: temp = "ERROR"; break;
    }
  }

  return temp;
}

void NumberWord::setNumber(uint64_t n)
{
  _n = n;
  nodes.clear();
  if (_n >= NUM_LIMIT) return;

  uint8_t p = 15;
  uint64_t temp{};
  for (uint64_t i = 1000000000000000; i != 0; i /= 1000, p -= 3)
  {
    if ((temp = n / i) > 0)
    {
      NumberNode *node = new NumberNode{ static_cast<uint16_t>(temp), p };
      nodes.push_back(node);
    }
    n %= i;
  }
}

std::string NumberWord::toString()
{
  if (_n == 0) return "";
  if (_n >= NUM_LIMIT) return "ERROR: TOO BIG NUMBER";

  std::stringstream ss;
  for (auto it = nodes.begin(); it != nodes.end(); ++it) {
    NumberNode *node = *it;
    ss << node->toString();
    if (it != nodes.end() - 1)
    {
      ss << " ";
    }
  }
  return ss.str();
}

// for std::cout
std::ostream& operator<<(std::ostream& os, NumberWord nw)
{
  return os << nw.toString();
}