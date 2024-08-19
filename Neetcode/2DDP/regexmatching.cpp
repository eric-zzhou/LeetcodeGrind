// https://neetcode.io/problems/regular-expression-matching
// https://leetcode.com/problems/regular-expression-matching

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> track(n + 1, vector<bool>(m + 1, false));
    track[0][0] = true;

    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
          track[i][j] = track[i][j - 2] ||
                        (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') &&
                         track[i - 1][j]);
        } else {
          track[i][j] = i > 0 && track[i - 1][j - 1] &&
                        (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
      }
    }

    return track[n][m];
  }
};

class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> track(n + 1, vector<bool>(m + 1, false));
    track[0][0] = true;

    for (int j = 1; j < m; j++) {
      if (p.at(j) == '*') {
        track[0][j + 1] = track[0][j - 1];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (p.at(j) == '.') {
          track[i + 1][j + 1] = track[i][j];
        } else if (p.at(j) == '*') {
          // cout << s.at(i) << ", " << p.at(j-1) << ", " << track[i+1][j] <<
          // endl;
          if (s.at(i) == p.at(j - 1) || p.at(j - 1) == '.') {
            track[i + 1][j + 1] = track[i][j + 1] || track[i][j];
          }
          track[i + 1][j + 1] = track[i + 1][j + 1] || track[i + 1][j - 1];
        } else {
          if (s.at(i) == p.at(j)) {
            track[i + 1][j + 1] = track[i][j];
          }
        }
        // track[i+][j+1] = ?;
      }
      // for (auto v : track) {
      //     for (auto v2 : v) {
      //         cout << v2 << " ";
      //     }
      //     cout << endl;
      // }
      // cout << endl;
    }
    return track[n][m];
  }
};
