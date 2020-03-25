#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept> // for std::invalid_argument

#define TRIAL3

using namespace std;

const int MAX = 10;

// template class to generate kth permutation
template<class T>
class Perumutation
{
private:
  long fact;
  int x;
  vector<T> input;
  vector<T> output;

  // calculates x!
  long factorial(int x);

public:
  /**
   * n: number of elements in the set of elements to be permuted
   * input: inital input set
   *
   * If we want to generate permutations for the set
   *   { "BLR", "CCU", "CHE", "DEL", "MUM" }
   * n = 5 and input will be vector containing above elements (in order)
   */
  Perumutation(int n, vector<T>& input);

  // generate kth permutation
  // 0 <= k <= n! (n = 5 in the above example)
  void getPurmetation(int k);
};

template<typename T>
Perumutation<T>::Perumutation(int n, vector<T>& input)
{
  if (n > MAX) {
    // supports only till MAX!
    throw invalid_argument("Max numported value is " + MAX);
  }
  x = n;
  fact = factorial(x);
  this->input.reserve(x); // pre-allocate space for input
  output.reserve(x);      //   and output

  // Copy the elements from input set
  for (int i = 0; i < n; ++i) {
    this->input.push_back(input.at(i));
  }
}

// calculates x! - this is an utiltiy function
template<typename T>
long Perumutation<T>::factorial(int x)
{
  long f = 1;

  if (x <= 0) return (long)1;

  while (x > 1) {
    f *= x--;
  }

  return f;
}

/**
 * generate kth permutation
 * 0 <= k <= n!
 *
 *   0    A B C D
 *   1    A B D C
 *   2    A C B D
 *   3    A C D B
 *   4    A D B C
 *   5    A D C B
 *      -----------
 *   6    B A C D
 *   7    B A D C
 *   8    B C A D
 *   9    B C D A
 *  10    B D A C
 *  11    B D C A
 *      -----------
 *  12    C A B D
 *  13    C A D B
 *       ---------
 *  14    C B A D
 *        -------
 *  15    C B D A
 *       ---------
 *  16    C D A B
 *  17    C D B A
 *      -----------
 *  18    D A B C
 *  19    D A C B
 *  20    D B A C
 *  21    D B C A
 *  22    D C A B
 *  23    D C B A
 */
template<typename T>
void Perumutation<T>::getPurmetation(int k)
{
  if ((k >= fact) || (k < 0)) { // check if 0 <= k <= n!
    cerr << "Invalid k";
    return;
  }
  int n = k + 1; // k_min = 0 => n_min = 1;
  long len = fact / x;
  int t = x - 1;

  auto srcBuf = input;
  output.clear();
  while (!srcBuf.empty()) {
    int g = 1;
    while (g * len < n) {
      g++;
    }
    // pick (g - 1)th element from source
    output.push_back(srcBuf.at(g - 1));
    srcBuf.erase(srcBuf.begin() + (g - 1));
    n -= len * (g - 1);
    if (t > 1)
      len /= t--;
  }

  cout << setw(3) << k << " ";
  for (auto it = output.begin(); it < output.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

int main()
{
#ifdef TRIAL1
  vector<int> a1 = { 1, 2, 3 };
  Perumutation<int> p1 = Perumutation<int>(3, a1);

  for (int i = 0; i < 6; ++i)
    p1.getPurmetation(i);
#endif

#ifdef TRIAL2
  vector<char> a2 = { 'A', 'B', 'C', 'D' };
  Perumutation<char> p2 = Perumutation<char>(4, a2);

  for (int i = 0; i < 24; ++i)
    p2.getPurmetation(i);
#endif

#ifdef TRIAL3
  vector<string> a3 = { "BLR", "CCU", "CHE", "DEL", "MUM" };
  Perumutation<string> p3 = Perumutation<string>(5, a3);

  for (int i = 0; i < 120; ++i)
    p3.getPurmetation(i);
#endif

  return 0;
}

///:~

/*

OUTPUT (TRIAL3)
---------------
  0 BLR CCU CHE DEL MUM
  1 BLR CCU CHE MUM DEL
  2 BLR CCU DEL CHE MUM
  3 BLR CCU DEL MUM CHE
  4 BLR CCU MUM CHE DEL
  5 BLR CCU MUM DEL CHE
  6 BLR CHE CCU DEL MUM
  7 BLR CHE CCU MUM DEL
  8 BLR CHE DEL CCU MUM
  9 BLR CHE DEL MUM CCU
 10 BLR CHE MUM CCU DEL
 11 BLR CHE MUM DEL CCU
 12 BLR DEL CCU CHE MUM
 13 BLR DEL CCU MUM CHE
 14 BLR DEL CHE CCU MUM
 15 BLR DEL CHE MUM CCU
 16 BLR DEL MUM CCU CHE
 17 BLR DEL MUM CHE CCU
 18 BLR MUM CCU CHE DEL
 19 BLR MUM CCU DEL CHE
 20 BLR MUM CHE CCU DEL
 21 BLR MUM CHE DEL CCU
 22 BLR MUM DEL CCU CHE
 23 BLR MUM DEL CHE CCU
 24 CCU BLR CHE DEL MUM
 25 CCU BLR CHE MUM DEL
 26 CCU BLR DEL CHE MUM
 27 CCU BLR DEL MUM CHE
 28 CCU BLR MUM CHE DEL
 29 CCU BLR MUM DEL CHE
 30 CCU CHE BLR DEL MUM
 31 CCU CHE BLR MUM DEL
 32 CCU CHE DEL BLR MUM
 33 CCU CHE DEL MUM BLR
 34 CCU CHE MUM BLR DEL
 35 CCU CHE MUM DEL BLR
 36 CCU DEL BLR CHE MUM
 37 CCU DEL BLR MUM CHE
 38 CCU DEL CHE BLR MUM
 39 CCU DEL CHE MUM BLR
 40 CCU DEL MUM BLR CHE
 41 CCU DEL MUM CHE BLR
 42 CCU MUM BLR CHE DEL
 43 CCU MUM BLR DEL CHE
 44 CCU MUM CHE BLR DEL
 45 CCU MUM CHE DEL BLR
 46 CCU MUM DEL BLR CHE
 47 CCU MUM DEL CHE BLR
 48 CHE BLR CCU DEL MUM
 49 CHE BLR CCU MUM DEL
 50 CHE BLR DEL CCU MUM
 51 CHE BLR DEL MUM CCU
 52 CHE BLR MUM CCU DEL
 53 CHE BLR MUM DEL CCU
 54 CHE CCU BLR DEL MUM
 55 CHE CCU BLR MUM DEL
 56 CHE CCU DEL BLR MUM
 57 CHE CCU DEL MUM BLR
 58 CHE CCU MUM BLR DEL
 59 CHE CCU MUM DEL BLR
 60 CHE DEL BLR CCU MUM
 61 CHE DEL BLR MUM CCU
 62 CHE DEL CCU BLR MUM
 63 CHE DEL CCU MUM BLR
 64 CHE DEL MUM BLR CCU
 65 CHE DEL MUM CCU BLR
 66 CHE MUM BLR CCU DEL
 67 CHE MUM BLR DEL CCU
 68 CHE MUM CCU BLR DEL
 69 CHE MUM CCU DEL BLR
 70 CHE MUM DEL BLR CCU
 71 CHE MUM DEL CCU BLR
 72 DEL BLR CCU CHE MUM
 73 DEL BLR CCU MUM CHE
 74 DEL BLR CHE CCU MUM
 75 DEL BLR CHE MUM CCU
 76 DEL BLR MUM CCU CHE
 77 DEL BLR MUM CHE CCU
 78 DEL CCU BLR CHE MUM
 79 DEL CCU BLR MUM CHE
 80 DEL CCU CHE BLR MUM
 81 DEL CCU CHE MUM BLR
 82 DEL CCU MUM BLR CHE
 83 DEL CCU MUM CHE BLR
 84 DEL CHE BLR CCU MUM
 85 DEL CHE BLR MUM CCU
 86 DEL CHE CCU BLR MUM
 87 DEL CHE CCU MUM BLR
 88 DEL CHE MUM BLR CCU
 89 DEL CHE MUM CCU BLR
 90 DEL MUM BLR CCU CHE
 91 DEL MUM BLR CHE CCU
 92 DEL MUM CCU BLR CHE
 93 DEL MUM CCU CHE BLR
 94 DEL MUM CHE BLR CCU
 95 DEL MUM CHE CCU BLR
 96 MUM BLR CCU CHE DEL
 97 MUM BLR CCU DEL CHE
 98 MUM BLR CHE CCU DEL
 99 MUM BLR CHE DEL CCU
100 MUM BLR DEL CCU CHE
101 MUM BLR DEL CHE CCU
102 MUM CCU BLR CHE DEL
103 MUM CCU BLR DEL CHE
104 MUM CCU CHE BLR DEL
105 MUM CCU CHE DEL BLR
106 MUM CCU DEL BLR CHE
107 MUM CCU DEL CHE BLR
108 MUM CHE BLR CCU DEL
109 MUM CHE BLR DEL CCU
110 MUM CHE CCU BLR DEL
111 MUM CHE CCU DEL BLR
112 MUM CHE DEL BLR CCU
113 MUM CHE DEL CCU BLR
114 MUM DEL BLR CCU CHE
115 MUM DEL BLR CHE CCU
116 MUM DEL CCU BLR CHE
117 MUM DEL CCU CHE BLR
118 MUM DEL CHE BLR CCU
119 MUM DEL CHE CCU BLR
*/
