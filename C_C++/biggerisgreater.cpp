#include <algorithm>  // for reverse()
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string w) {
  auto it1 {w.end() - 1}, it2 {it1 - 1};  // last two chars

  while (it1 != w.begin()) {
    if (*it2 >= *it1) {
      it1--;
      it2--;
    } else
      break;
  }
  if (it1 == w.begin())
    return "no answer";

  string::iterator it3 {it1};
  while (it3 != w.end()) {
    if (*it3 > *it2) {
      it3++;
    } else
      break;
  }
  auto temp = *(it3 - 1);
  *(it3 - 1) = *it2;
  *it2 = temp;

  reverse(it1, w.end());

  return w;
}

int main() {
  string inputs[] = {"ab", "bb", "hefg", "dhck", "dkhc", "lmno",
                     "dcba", "dcbb", "abdc", "abcd", "fedcbabcd"};
  string outputs[] = {"ba", "no answer", "hegf", "dhkc",
                      "hcdk", "lmon", "no answer", "no answer",
                      "acbd", "abdc", "fedcbabdc"};

  int i = 0;
  for (auto w : inputs) {
    string s = biggerIsGreater(w);
    assert(s == outputs[i++]);
    // cout << s << endl;
  }
  return 0;
}