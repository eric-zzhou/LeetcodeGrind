// https://leetcode.com/problems/spiral-matrix/

#include <vector>
using namespace std;

class AlternateSolution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int lb = 0, tb = 0;
    int rb = matrix[0].size(), bb = matrix.size();
    int tot = rb * bb;
    vector<int> ret(tot);

    int ind = 0;
    while (ind < tot) {
      for (int i = lb; i < rb && ind < tot; i++) {
        ret[ind++] = matrix[tb][i];
      }
      tb++;
      for (int i = tb; i < bb && ind < tot; i++) {
        ret[ind++] = matrix[i][rb - 1];
      }
      rb--;
      for (int i = rb - 1; i >= lb && ind < tot; i--) {
        ret[ind++] = matrix[bb - 1][i];
      }
      bb--;
      for (int i = bb - 1; i >= tb && ind < tot; i--) {
        ret[ind++] = matrix[i][lb];
      }
      lb++;
    }
    return ret;
  }
};

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int lb = 0, tb = 0;
    int rb = matrix[0].size(), bb = matrix.size();
    int tot = rb * bb;
    vector<int> ret(tot);

    int ind = 0;
    int j = 0;
    while (ind < tot) {
      if (j % 4 == 0) {
        for (int i = lb; i < rb; i++) {
          ret[ind++] = matrix[tb][i];
        }
        tb++;
      } else if (j % 4 == 1) {
        for (int i = tb; i < bb; i++) {
          ret[ind++] = matrix[i][rb - 1];
        }
        rb--;
      } else if (j % 4 == 2) {
        for (int i = rb - 1; i >= lb; i--) {
          ret[ind++] = matrix[bb - 1][i];
        }
        bb--;
      } else {
        for (int i = bb - 1; i >= tb; i--) {
          ret[ind++] = matrix[i][lb];
        }
        lb++;
      }
      j++;
    }
    return ret;
  }
};