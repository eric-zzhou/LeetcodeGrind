// https://leetcode.com/problems/spiral-matrix-ii/description/

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, vector<int>(n));
    int lb = 0, tb = 0;
    int rb = n, bb = n;

    int ind = 1, tot = n * n;
    while (ind <= tot) {
      for (int i = lb; i < rb && ind <= tot; i++) {
        ret[tb][i] = ind++;
      }
      tb++;
      for (int i = tb; i < bb && ind <= tot; i++) {
        ret[i][rb - 1] = ind++;
      }
      rb--;
      for (int i = rb - 1; i >= lb && ind <= tot; i--) {
        ret[bb - 1][i] = ind++;
      }
      bb--;
      for (int i = bb - 1; i >= tb && ind <= tot; i--) {
        ret[i][lb] = ind++;
      }
      lb++;
    }
    return ret;
  }
};