#include <iostream>
#include <string>

using namespace std;

static void permutation(string des, string src)
{
  if (src.length() == 0) {
    cout << des << endl;
    return;
  }

  for (size_t i = 0; i < src.length(); ++i) {
    permutation(des + src.at(i), src.substr(0, i) + src.substr(i + 1, src.length() - i - 1));
  }
}

static void permutation(char alreadyIncludedIndices[], char des[], int d, 
                        char src[], int end)
{
  if (d == end) {
    des[d] = '\0';
    cout << des << endl;
    return;
  }

  for (int i = 0; i < end; ++i) {
    if (alreadyIncludedIndices[i] == 0) {
      alreadyIncludedIndices[i] = 1;
      des[d] = src[i];
      permutation(alreadyIncludedIndices, des, d + 1, src, end);
      // backtrack
      alreadyIncludedIndices[i] = 0;
      des[d] = '\0';
    }
  }
}

void main()
{
  string a = "abc";
  cout << "Implementation 1 (implict backtracking)\n";
  permutation("", a);

  char alreadyIncludedIndices[4] = { 0 };
  char des[5] = { 0 };
  cout << "Implementation 2 (explict backtracking)\n";
  permutation(alreadyIncludedIndices, des, 0, "1234", 4);
}

//:~
/*
OUTPUT

Implementation 1 (implict backtracking)
abc
acb
bac
bca
cab
cba
Implementation 2 (explict backtracking)
1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
2413
2431
3124
3142
3214
3241
3412
3421
4123
4132
4213
4231
4312
4321
*/
