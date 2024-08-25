// https://leetcode.com/problems/rotate-image/submissions/1351819250/

#include <vector>
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) swap(matrix[i][j], matrix[j][i]);
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

class MySolution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int r = 0; r < n / 2; r++) {
      for (int o = 0; o < n - r - r - 1; o++) {
        int temp = matrix[n - r - o - 1][r];
        matrix[n - r - o - 1][r] = matrix[n - r - 1][n - r - o - 1];
        matrix[n - r - 1][n - r - o - 1] = matrix[r + o][n - r - 1];
        matrix[r + o][n - r - 1] = matrix[r][r + o];
        matrix[r][r + o] = temp;
      }
    }
  }
};