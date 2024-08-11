// https://leetcode.com/problems/diagonal-traverse/submissions/1351928624/

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    vector<int> res;
    int i = 0, j = 0, n = mat.size(), m = mat[0].size(), add = -1;
    res.push_back(mat[i][j]);
    while (i < n - 1 || j < m - 1) {
      // Switch direction at the edges of the matrix
      if (j < m - 1 && ((i == 0 && add == -1) || (i == n - 1 && add == 1))) {
        ++j;
        add = -add;
      } else if ((j == 0 && add == 1) || (j == m - 1 && add == -1)) {
        ++i;
        add = -add;
      }

      // Move along the diagonal
      else {
        i += add;
        j -= add;
      }

      // Add the element to the result
      res.push_back(mat[i][j]);
    }
    return res;
  }
};

class GPTSolution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return {};

    int m = mat.size(), n = mat[0].size();
    vector<int> ret;
    bool up = true;

    for (int d = 0; d < m + n - 1; d++) {
      if (up) {
        int r = d < m ? d : m - 1;
        int c = d < m ? 0 : d - m + 1;
        while (r >= 0 && c < n) {
          ret.push_back(mat[r--][c++]);
        }
      } else {
        int r = d < n ? 0 : d - n + 1;
        int c = d < n ? d : n - 1;
        while (r < m && c >= 0) {
          ret.push_back(mat[r++][c--]);
        }
      }
      up = !up;
    }
    return ret;
  }
};

class MyHorrendousSolution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();

    vector<int> ret;
    int size = 1;
    bool up = true;
    for (int ind = 0; ind < n; ind++) {
      // cout << up << ": ";
      for (int i = 0; i < size; i++) {
        if (up) {
          // cout << size - 1 - i << ", " << ind - size + 1 + i << "   ";
          ret.push_back(mat[size - 1 - i][ind - size + 1 + i]);
        } else {
          // cout << i << ", " << ind - i << "   ";
          ret.push_back(mat[i][ind - i]);
        }
      }
      up = !up;
      size = min(size + 1, m);
      // cout << endl;
    }
    int diff = m - n;
    size--;
    for (int ind = 1; ind < m; ind++) {
      // cout << up << ": ";
      for (int i = 0; i < size; i++) {
        if (up) {
          // cout << ind + size - 1 - i << ", " << n - size + i << "   ";
          ret.push_back(mat[ind + size - 1 - i][n - size + i]);
        } else {
          // cout << ind + i << ", " << n - 1 - i << "   ";
          ret.push_back(mat[ind + i][n - 1 - i]);
        }
      }
      up = !up;
      if (diff > 1) {
        diff--;
      } else {
        size--;
      }
      // cout << endl;
    }
    return ret;
  }
};