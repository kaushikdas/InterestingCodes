#include <iostream>
#include <string>

using namespace std;

namespace kd 
{

constexpr auto NUM_LIMIT = 1000000000000000000;

class NumberWord
{
private:
    uint64_t _n;    // The number to get word presentation for
    std::string _getWord(uint64_t n);

    std::string _getWord3Digits(uint16_t x);

    std::string _getWord2Digits(uint8_t x);
    
    std::string _getWord1Digit(uint8_t x);
public:
    NumberWord(uint64_t n) : _n{n} { };
    NumberWord() = default;

    void setNumber(uint64_t n) { _n = n; };
    uint64_t getNumber() const { return _n; };

    std::string getWord() { return (_n == 0) ? "zero" : _getWord(_n); };

    // conversion operator
    operator std::string() { return getWord(); };
};

std::string NumberWord::_getWord1Digit(uint8_t x)
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

std::string NumberWord::_getWord2Digits(uint8_t x)
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
    std::string temp {""};
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

    uint8_t y { static_cast<uint8_t>(x % 10) };
    if (y > 0) 
    {
        temp += "-" + _getWord1Digit(y);
    }

    return temp;
}

std::string NumberWord::_getWord3Digits(uint16_t x)
{
    if (x < 10) return _getWord1Digit(static_cast<uint8_t>(x));
    if (x < 100) return _getWord2Digits(x);

    std::string temp {""};
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

    uint8_t y { static_cast<uint8_t>(x % 100) };
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

std::string NumberWord::_getWord(uint64_t n)
{
    if (n == 0) return "";
    if (n >= NUM_LIMIT) return "ERROR: TOO BIG NUMBER"; 

    std::string result{""};
    for (uint64_t i = 1000000000000000; i != 0; i /= 1000)
    {
        uint64_t temp = n / i;
        if (temp != 0) {
            switch (i)
            {
            case 1000000000000000:
                result += _getWord3Digits(temp) + "-quadrillion ";
                break;
            case 1000000000000:
                result += _getWord3Digits(temp) + "-trillion ";
                break;
            case 1000000000:
                result += _getWord3Digits(temp) + "-billion ";
                break;
            case 1000000:
                result += _getWord3Digits(temp) + "-million ";
                break;
            case 1000:
                result += _getWord3Digits(temp) + "-thousand ";
                break;
            case 1:
                result += _getWord3Digits(temp);
                break;
            default:
                break;
            }
            n %= i;
        }

        // Erase any trailing spaces
        result.erase(result.find_last_not_of(" ") + 1);
    }

    return result;
}

}

// for std::cout
std::ostream& operator<<(std::ostream& os, kd::NumberWord nw)
{
    return os << nw.getWord();
}

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << "Number word client" << endl;
    kd::NumberWord nw;

    int tc{};
    std::cin >> tc;
    for (int t = 0; t < tc; ++t)
    {
        uint64_t n{};
        std::cin >> n;
        nw.setNumber(n);
        std::cout << "Number is " << n << " (" << nw << ")" << endl;
    }
    return 0;
}

/*//~
>.\a.exe < number_word_input.txt
Number word client
Number is 3 (three)
Number is 47 (forty-seven)
Number is 73 (seventy-three)
Number is 1492 (one-thousandfour-hundred ninty-two)
Number is 10012 (ten-thousandtwelve)
Number is 100073 (one-hundred-thousandseventy-three)
Number is 1000000 (one-million)
Number is 1000000001 (one-billionone)
Number is 100000000000 (one-hundred-billion)
Number is 474142398123 (four-hundred seventy-four-billionone-hundred forty-two-millionthree-hundred ninty-eight-thousandone-hundred twenty-three)     
Number is 1474142398007 (one-trillionfour-hundred seventy-four-billionone-hundred forty-two-millionthree-hundred ninty-eight-thousandseven)
Number is 999000000000000 (nine-hundred ninty-nine-trillion)
Number is 999999999999999999 (nine-hundred ninty-nine-quadrillionnine-hundred ninty-nine-trillionnine-hundred ninty-nine-billionnine-hundred ninty-nine-millionnine-hundred ninty-nine-thousandnine-hundred ninty-nine)
Number is 1000000000000000000 (ERROR: TOO BIG NUMBER)
//~*/