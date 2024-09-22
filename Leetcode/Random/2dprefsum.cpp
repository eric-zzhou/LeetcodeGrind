// https://leetcode.com/problems/range-sum-query-2d-immutable/

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& m) : matrix{std::move(m)} {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (size_t j = 1; j < matrix[0].size(); ++j) {
      matrix[0][j] += matrix[0][j - 1];
    }
    for (size_t i = 1; i < matrix.size(); ++i) {
      matrix[i][0] += matrix[i - 1][0];
      for (size_t j = 1; j < matrix[i].size(); ++j) {
        matrix[i][j] +=
            matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    // Upper left: (row1, col1)
    // Lower right: (row2, col2)
    int upper_left = (row1 > 0 && col1 > 0) ? matrix[row1 - 1][col1 - 1] : 0;
    int upper_right = (row1 > 0) ? matrix[row1 - 1][col2] : 0;
    int lower_left = (col1 > 0) ? matrix[row2][col1 - 1] : 0;
    int lower_right = matrix[row2][col2];

    return lower_right - lower_left - upper_right + upper_left;
  }

 private:
  vector<vector<int>> matrix;
};

class NumMatrix {
 private:
  vector<vector<int>> pfsum;

 public:
  NumMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int curr;
    for (int i = 0; i < n; i++) {
      vector<int> temp(m, 0);
      for (int j = 0; j < m; j++) {
        curr = 0;
        if (j != 0) {
          curr += temp[j - 1];
        }
        if (i != 0) {
          curr += pfsum[i - 1][j];
          if (j != 0) {
            curr -= pfsum[i - 1][j - 1];
          }
        }
        temp[j] = matrix[i][j] + curr;
      }
      pfsum.push_back(temp);
    }
    for (auto v : pfsum) {
      for (auto v2 : v) {
        cout << v2 << " ";
      }
      cout << endl;
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (pfsum.size() == 0) return 0;
    int num = pfsum[row2][col2];
    int left = 0, upper = 0, leftupper = 0;

    if (col1 > 0 && row1 > 0) leftupper = pfsum[row1 - 1][col1 - 1];
    if (col1 > 0) left = pfsum[row2][col1 - 1];
    if (row1 > 0) upper = pfsum[row1 - 1][col2];

    return num - left - upper + leftupper;
  }
};