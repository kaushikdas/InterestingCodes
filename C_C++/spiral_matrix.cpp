/**
 * SPIRAL MATRIX [https://leetcode.com/problems/spiral-matrix-ii/] 
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

using matrix_t = vector<vector<int>>;

class spiral_matrix
{
private:
  enum direction
  {
    RIGHT,
    DOWN,
    LEFT,
    UP
  };

  const int MOVES[4][2] = {
    { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0}
  };

  const direction NEXT_DIRECTION[4] = {
    DOWN, LEFT, UP, RIGHT
  };

  int _n;
  direction _d;

  inline bool _is_dead_end(int i, int j, const matrix_t& matrix) const
  {
    int next_i = i + MOVES[_d][0];
    int next_j = j + MOVES[_d][1];

    if ((next_i >= _n) || (next_j >= _n)
        || (next_i < 0) || (next_j < 0)
        || (0 != matrix[next_i][next_j]))
      return true;

    return false;
  }

  inline void _make_move(int& i, int&j)
  {
    i += MOVES[_d][0];
    j += MOVES[_d][1];
  }

public:
  spiral_matrix(int n) { _n = n; _d = direction::RIGHT; };
  ~spiral_matrix() { };

  matrix_t generate_matrix();
};

matrix_t spiral_matrix::generate_matrix()
{
  vector<int> row(_n, 0);
  matrix_t matrix(_n, row);

  if (0 == _n) return matrix;

  _d = direction::RIGHT;
  int r = 0, c = 0;
  for (size_t i = 0; i < _n; i++)
  {
    for (size_t j = 0; j < _n; j++)
    {
      matrix[r][c] = i * _n + j + 1;
      if (_is_dead_end(r, c, matrix)) {
        _d = NEXT_DIRECTION[_d];
      }
      _make_move(r, c);
    }
  }

  return matrix;
}

int main()                                                       
{        
  int n;
  cout << "n? ";
  cin >> n;

  spiral_matrix s(n);
  auto matrix = s.generate_matrix();

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << setw(4) << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;              
}

/*
❯ .\a.exe
n? 5
   1    2    3    4    5 
  16   17   18   19    6
  15   24   25   20    7
  14   23   22   21    8
  13   12   11   10    9
*/