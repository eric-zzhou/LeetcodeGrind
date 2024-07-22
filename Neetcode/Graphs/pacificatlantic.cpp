#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  void dfs(int i, int j, vector<vector<int>>& h, vector<vector<int>>& island,
           int prev) {
    if (i < 0 || j < 0 || i >= h.size() || j >= h[0].size() ||
        island[i][j] == 1) {
      return;
    }

    int curr = h[i][j];
    if (prev > curr) {
      return;
    }

    island[i][j] = 1;
    dfs(i + 1, j, h, island, curr);
    dfs(i - 1, j, h, island, curr);
    dfs(i, j + 1, h, island, curr);
    dfs(i, j - 1, h, island, curr);
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
    int n = h.size();
    int m = h[0].size();

    vector<vector<int>> res;
    vector<vector<int>> paci(n, vector<int>(m, 0));
    vector<vector<int>> atla(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 || j == 0) {
          dfs(i, j, h, paci, 0);
        }
        if (i == n - 1 || j == m - 1) {
          dfs(i, j, h, atla, 0);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (paci[i][j] && atla[i][j]) {
          res.push_back({i, j});
        }
      }
    }

    return res;
  }
};

class WorseSolution {
 public:
  void dfs(vector<vector<int>>& heights, unordered_set<int>& visit, int curr,
           int i, int j, int HEIGHT, int WIDTH) {
    if (i < 0 || i >= HEIGHT || j < 0 || j >= WIDTH ||
        visit.find(i * WIDTH + j) != visit.end() || heights[i][j] < curr) {
      return;
    }

    visit.insert(i * WIDTH + j);

    dfs(heights, visit, heights[i][j], i + 1, j, HEIGHT, WIDTH);
    dfs(heights, visit, heights[i][j], i - 1, j, HEIGHT, WIDTH);
    dfs(heights, visit, heights[i][j], i, j - 1, HEIGHT, WIDTH);
    dfs(heights, visit, heights[i][j], i, j + 1, HEIGHT, WIDTH);
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int HEIGHT = heights.size(), WIDTH = heights[0].size();
    unordered_set<int> atl, pac;

    for (int i = 0; i < HEIGHT; i++) {
      dfs(heights, pac, 0, i, 0, HEIGHT, WIDTH);
      dfs(heights, atl, 0, i, WIDTH - 1, HEIGHT, WIDTH);
    }

    for (int j = 0; j < WIDTH; j++) {
      dfs(heights, pac, 0, 0, j, HEIGHT, WIDTH);
      dfs(heights, atl, 0, HEIGHT - 1, j, HEIGHT, WIDTH);
    }

    vector<vector<int>> ret;
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        if (atl.find(i * WIDTH + j) != atl.end() &&
            pac.find(i * WIDTH + j) != pac.end()) {
          ret.push_back({i, j});
        }
      }
    }
    return ret;
  }
};
