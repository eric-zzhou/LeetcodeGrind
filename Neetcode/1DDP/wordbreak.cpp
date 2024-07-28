#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size(), m;
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i < n + 1; ++i) {
      for (string word : wordDict) {
        m = word.size();
        if (i >= m) {
          if (dp[i - m] && s.substr(i - m, m) == word) {
            dp[i] = true;
          }
        }
      }
    }
    return dp[n];
  }
};
