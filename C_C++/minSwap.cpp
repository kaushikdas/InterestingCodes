// https://www.hackerrank.com/challenges/minimum-swaps-2/problem
#include <iostream>
#include <vector>

static int minSwap(std::vector<int> arr)
{
  int swapCnt = 0, i = 0;

  while (i < arr.size())
  {
    if (arr[i] != i + 1) // i+1 is not at its right place (i)
    {
#ifdef DEBUG
      std::cout << "swap(" << i << ", " << arr[i] - 1 << ")"
                << " [" << arr[i] << ", " << arr[arr[i] - 1] << "]\n";
#endif //DEBUG
      std::swap(arr[i], arr[arr[i] - 1]);
      swapCnt += 1;
      // do not got to next element till arr[i] == i+1
    }
    else // i+1 is at its right place (i), check next index
      i++;
  }
  return swapCnt;
}

int main()
{
  std::vector<int> arr{4, 3, 1, 2}; //{7, 1, 3, 2, 4, 5, 6};

  int swapCnt = minSwap(arr);
  std::cout << swapCnt << std::endl;
}