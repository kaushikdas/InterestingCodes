// https://leetcode.com/problems/unique-paths-ii/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int makeMove(vector<vector<int>>& obstacleGrid,
                 vector<vector<int>>& grid,
                 int nexti,
                 int nextj) {
        int count = 0;
        if (grid[nexti][nextj] == -1) {
            if (obstacleGrid[nexti][nextj] != 1) {
                count = searchPath(obstacleGrid, grid, nexti, nextj);
            }
            else { // next cell is blocked
                count = grid[nexti][nextj] = 0;
            }
        }
        else {
            count = grid[nexti][nextj];
        }

        return count;
    }

    int searchPath(vector<vector<int>>& obstacleGrid,
        vector<vector<int>>& grid,
        int i,
        int j) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if ((i == (m - 1)) && (j == (n - 1))) {
            // reached destination
            return 1;
        }

        int right = 0, down = 0;
        // try right
        if ((j + 1) < n) {
            right = makeMove(obstacleGrid, grid, i, j + 1);
        }

        // try down
        if ((i + 1) < m) {
            down = makeMove(obstacleGrid, grid, i + 1, j);
        }

        return (grid[i][j] = right + down);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if ((obstacleGrid.size() == 0) || (obstacleGrid[0].size() == 0)
            || (obstacleGrid[0][0] == 1)) // intial cell itself is blocked
            return 0;

        vector<vector<int>> grid(obstacleGrid.size(),
            vector<int>(obstacleGrid[0].size(), -1));

        return searchPath(obstacleGrid, grid, 0, 0);
    }
};

int lc_unique_path_2_main() {
    vector<vector<int>> vi{ {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };

    // cout << vi.size() << " " << vi[0].size();

    Solution sln;
    cout << sln.uniquePathsWithObstacles(vi);

    return 0;
}