#include <vector>
using namespace std;

class Solution
{
public:
  void dfs(vector<vector<int>> &grid, int i, int j, int curr)
  {
    grid[i][j] = curr;
    if (i + 1 < grid.size() && curr + 1 < grid[i + 1][j])
    {
      dfs(grid, i + 1, j, curr + 1);
    }
    if (i - 1 >= 0 && curr + 1 < grid[i - 1][j])
    {
      dfs(grid, i - 1, j, curr + 1);
    }
    if (j + 1 < grid[0].size() && curr + 1 < grid[i][j + 1])
    {
      dfs(grid, i, j + 1, curr + 1);
    }
    if (j - 1 >= 0 && curr + 1 < grid[i][j - 1])
    {
      dfs(grid, i, j - 1, curr + 1);
    }
  }

  void islandsAndTreasure(vector<vector<int>> &grid)
  {
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 0)
        {
          dfs(grid, i, j, 0);
        }
      }
    }
  }
};
