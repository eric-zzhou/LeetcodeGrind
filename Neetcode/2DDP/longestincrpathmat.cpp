// https://neetcode.io/problems/longest-increasing-path-in-matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include <iostream>
#include <vector>
using namespace std;

// MY SOLUTION WAS OPTIMAL !!!
class MySolution {
 public:
  int dfs(vector<vector<int>>& matrix, vector<vector<int>>& track, int i, int j,
          int n, int m) {
    if (track[i][j] != -1) {
      return track[i][j];
    }
    int ret = 1, curr = matrix[i][j];
    if (i > 0 && matrix[i - 1][j] < curr) {
      ret = dfs(matrix, track, i - 1, j, n, m) + 1;
    }
    if (i < n - 1 && matrix[i + 1][j] < curr) {
      ret = max(ret, dfs(matrix, track, i + 1, j, n, m) + 1);
    }
    if (j > 0 && matrix[i][j - 1] < curr) {
      ret = max(ret, dfs(matrix, track, i, j - 1, n, m) + 1);
    }
    if (j < m - 1 && matrix[i][j + 1] < curr) {
      ret = max(ret, dfs(matrix, track, i, j + 1, n, m) + 1);
    }
    track[i][j] = ret;
    return ret;
  }

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> track(n, vector<int>(m, -1));
    int ret = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (track[i][j] == -1) {
          ret = max(ret, dfs(matrix, track, i, j, n, m));
        }
      }
    }

    // for (auto a : track) {
    //   for (auto v : a) {
    //     cout << v << " ";
    //   }
    //   cout << endl;
    // }

    return ret;
  }
};
