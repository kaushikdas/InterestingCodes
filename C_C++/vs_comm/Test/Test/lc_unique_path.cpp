// https://leetcode.com/problems/unique-paths/

#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Solution {
    int pathCnt;
    int M, N;

    int searchPath(vector<vector<int>>& grid, int i, int j)
    {
        int right = 0, down = 0;

        if ((i == (M - 1)) && (j == (N - 1))) {
            // reached destination
            return 1;  // break recursion
        }

        // try right
        if ((j + 1) < N) {
            if (grid[i][j + 1] == -1) {
                right = searchPath(grid, i, j + 1);
            }
            else {
                right = grid[i][j + 1];
            }
        }
        // try down
        if ((i + 1) < M) {
            if (grid[i + 1][j] == -1) {
                down = searchPath(grid, i + 1, j);
            }
            else {
                down = grid[i + 1][j];
            }
        }

        // reset this cell as UNEXPLORED
        grid[i][j] = right + down;

        return grid[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        if ((m < 1) || (m > 100) || (n < 1) || (n > 100))
            return 0;

        vector<vector<int>> grid(m, vector<int>(n, -1));

        pathCnt = 0;
        M = m;
        N = n;

        pathCnt = searchPath(grid, 0, 0);

        return pathCnt;
    }
};

int lc_unique_path_main()
{
    Solution sln;

    // cout << sln.uniquePaths(3, 7) << "\n";

    // cout << sln.uniquePaths(100, 100) << "\n";

    cout << sln.uniquePaths(3, 4) << "\n";

    return 0;
}