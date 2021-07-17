// https://www.hackerrank.com/challenges/encryption/problem
#include <string>
#include <sstream>
#include <iostream>
#include <cassert>

using namespace std;

class EncryptionSoln
{
public:
  string encryption(string s)
  {
    stringstream src_buff;
    int L{};
    for (auto c : s)
    {
      if (c != ' ')
      {
        src_buff << c;
        L++;
      }
    }
    string src = src_buff.str();

    int n = 2;
    while (n * n < L)
    {
      n += 1;
    }

    stringstream result;
    for (auto j = 0; j < n; j++)
    {
      for (auto k = j; k < L; k += n)
      {
        result << src[k];
      }
      if (j != n - 1)
        result << ' ';
    }

    return result.str();
  }
};

int main()
{
  EncryptionSoln e;

  string s = e.encryption("haveaniceday");
  assert(s == "hae and via ecy");
  cout << s << endl;
  s = e.encryption("feedthedog");
  assert(s == "fto ehg ee dd");
  cout << s << endl;
}