// https://neetcode.io/problems/interleaving-string
// https://leetcode.com/problems/interleaving-string/

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool inter(string &s1, string &s2, int i, int j, string &s3,
             vector<vector<int>> &dp) {
    if (i + j > s3.size()) {
      return false;
    }
    if (i + j == s3.size() && i == s1.size() && j == s2.size()) {
      return true;
    }

    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    bool b = false;

    if (i < s1.size() && s1[i] == s3[i + j]) {
      b = b || inter(s1, s2, i + 1, j, s3, dp);
    }
    if (j < s2.size() && s2[j] == s3[i + j]) {
      b = b || inter(s1, s2, i, j + 1, s3, dp);
    }
    dp[i][j] = b;

    return b;
  }

  bool isInterleave(string s1, string s2, string s3) {
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return inter(s1, s2, 0, 0, s3, dp);
  }
};

class DumbSolution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n1 + n2 != n3) {
      return false;
    }

    vector<vector<bool>> track(n1 + 1, vector<bool>(n2 + 1, false));
    track[0][0] = true;
    for (int i = 0; i <= n1; i++) {
      for (int j = 0; j <= n2; j++) {
        if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
          track[i][j] = track[i][j] || track[i - 1][j];
        }
        if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
          track[i][j] = track[i][j] || track[i][j - 1];
        }
      }
    }

    return track[n1][n2];
  }
};
