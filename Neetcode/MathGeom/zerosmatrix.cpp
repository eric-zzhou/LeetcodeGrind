// https://neetcode.io/problems/set-zeroes-in-matrix
// https://leetcode.com/problems/set-matrix-zeroes

#include <vector>
using namespace std;

// Space O(1) Solution
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();

    // Track if first row and first column should be zeroed
    bool firstRow = false, firstCol = false;
    for (int i = 0; i < n; i++) {
      if (matrix[i][0] == 0) {
        firstCol = true;
        break;
      }
    }
    for (int j = 0; j < m; j++) {
      if (matrix[0][j] == 0) {
        firstRow = true;
        break;
      }
    }

    // Use first row and first column to track zeros
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    // Zero out rows and columns
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
      }
    }

    // Zero out first row and first column
    if (firstRow) {
      for (int j = 0; j < m; j++) matrix[0][j] = 0;
    }
    if (firstCol) {
      for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }
  }
};

class BasicSolution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    vector<int> rows, cols;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          rows.push_back(i);
          cols.push_back(j);
        }
      }
    }
    for (int i = 0; i < rows.size(); i++) {
      for (int j = 0; j < n; j++) {
        matrix[rows[i]][j] = 0;
      }
    }
    for (int i = 0; i < cols.size(); i++) {
      for (int j = 0; j < m; j++) {
        matrix[j][cols[i]] = 0;
      }
    }
  }
};