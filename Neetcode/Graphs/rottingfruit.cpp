#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>> &grid) {
    int HEIGHT = grid.size();
    int WIDTH = grid[0].size();

    int fruits = 0;
    int ret = 0;
    queue<pair<int, int>> rotten;

    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        if (grid[i][j] == 1) {
          fruits++;
        } else if (grid[i][j] == 2) {
          rotten.push({i, j});
        }
      }
    }

    while (fruits > 0 && !rotten.empty()) {
      int stepsize = rotten.size();
      for (int k = 0; k < stepsize; k++) {
        auto curr = rotten.front();
        rotten.pop();
        int i = curr.first;
        int j = curr.second;

        if (i + 1 < HEIGHT && grid[i + 1][j] == 1) {
          grid[i + 1][j] = 2;
          fruits--;
          rotten.push({i + 1, j});
        }
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
          grid[i - 1][j] = 2;
          fruits--;
          rotten.push({i - 1, j});
        }
        if (j + 1 < WIDTH && grid[i][j + 1] == 1) {
          grid[i][j + 1] = 2;
          fruits--;
          rotten.push({i, j + 1});
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
          grid[i][j - 1] = 2;
          fruits--;
          rotten.push({i, j - 1});
        }
      }
      ret++;
    }

    return fruits == 0 ? ret : -1;
  }
};