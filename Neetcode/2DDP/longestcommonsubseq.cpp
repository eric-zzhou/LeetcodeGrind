#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();

    // dp[i][j] represents longest common subseq of text1[:i+1] and text2[:j+1]
    int** dp = new int*[n];
    for (int i = 0; i < n; i++) {
      dp[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (text1[i] == text2[j]) {
          dp[i][j] = 1 + (min(i, j) == 0 ? 0 : dp[i - 1][j - 1]);
        } else {
          dp[i][j] =
              max((i > 0 ? dp[i - 1][j] : 0), (j > 0 ? dp[i][j - 1] : 0));
        }
      }
    }

    return dp[n - 1][m - 1];
  }
};

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();

    // track[i][j] represents longest common subseq of text1[:i] and text2[:j]
    vector<vector<int>> track(n + 1, vector<int>(m + 1));

    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        if (text1.at(i - 1) == text2.at(j - 1)) {
          track[i][j] = 1 + track[i - 1][j - 1];
        } else {
          track[i][j] = max(track[i - 1][j], track[i][j - 1]);
        }
      }
    }
    return track[n][m];
  }
};
