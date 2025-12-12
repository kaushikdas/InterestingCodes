#include <vector>
#include <iostream>
#include <cassert>

class Solution {
public:
    int binaryGap(int n) {
        auto x = n;
        int gap = 0, max_gap = -1;
        bool started = false;

        while (x > 0) {
            if ((x & 1) == 1) {
                if (started) {
                    // end of a gap
                    if (gap > max_gap) {
                        max_gap = gap;
                    }
                    // reset gap counting
                    gap = 0;
                }
                started = true;
            }
            else {
                if (started) {
                    // a continuing gap
                    gap += 1;
                }
            }

            x >>= 1;
        }

        return max_gap + 1;
    }
};

int lc_binary_gap_main()
{
    std::vector<int> input = { 6, 22, 8, 5, 3 };
    std::vector<int> output = { 1, 2, 0, 2, 1 };

    Solution sln = Solution();

    for (size_t i{}; i < input.size(); ++i) {
        auto res = sln.binaryGap(input[i]);
        assert(res == output[i]);
    }

    std::cout << "\n>> [lc_binary_gap_main] PASSED\n";

    return 0;
}