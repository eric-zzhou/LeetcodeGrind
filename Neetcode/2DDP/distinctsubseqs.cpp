// https://neetcode.io/problems/count-subsequences
// https://leetcode.com/problems/distinct-subsequences

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Still my solution but slightly optimized
class Solution {
 public:
  int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    // track[i][j] is # of ways to make t[:j] from s[:i]
    vector<vector<double>> track(n + 1, vector<double>(m + 1, 0));
    for (int i = 0; i < n; i++) {
      track[i][0] = 1;
    }

    for (int j = 0; j < m; j++) {
      for (int i = j; i < n; i++) {
        track[i + 1][j + 1] = track[i][j + 1];
        if (s.at(i) == t.at(j)) {
          track[i + 1][j + 1] += track[i][j];
        }
      }
    }
    return track[n][m];
  }
};

class MySolution {
 public:
  int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    // track[i][j] is # of ways to make t[:j] from s[:i]
    vector<vector<double>> track(n + 1, vector<double>(m + 1, 0));
    for (int i = 0; i < n; i++) {
      track[i][0] = 1;
    }

    for (int j = 0; j < m; j++) {
      for (int i = j; i < n; i++) {
        if (s.at(i) == t.at(j)) {
          track[i + 1][j + 1] = track[i][j + 1] + track[i][j];
        } else {
          track[i + 1][j + 1] = track[i][j + 1];
        }
      }
    }

    // for (auto a : track) {
    //     for (auto v : a) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    return track[n][m];
  }
};
