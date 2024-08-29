// https://leetcode.com/problems/count-sub-islands/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m,
           int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid2[i][j] == 0) return true;
    grid2[i][j] = 0;
    bool ret = (grid1[i][j] == 1);
    ret = dfs(grid1, grid2, n, m, i + 1, j) && ret;
    ret = dfs(grid1, grid2, n, m, i - 1, j) && ret;
    ret = dfs(grid1, grid2, n, m, i, j + 1) && ret;
    ret = dfs(grid1, grid2, n, m, i, j - 1) && ret;
    return ret;
  }
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int n = grid1.size();
    int m = grid1[0].size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid2[i][j] == 1) {
          if (dfs(grid1, grid2, n, m, i, j)) {
            ret++;
          }
        }
      }
    }
    return ret;
  }
};