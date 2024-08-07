// https://neetcode.io/problems/edit-distance
// https://leetcode.com/problems/edit-distance/

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    if (n == 0 && m == 0) return 0;
    if (n == 0 || m == 0) return n + m;

    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Initialize top row of track
    for (int i = 0; i <= m; i++) {
      prev[i] = i;
    }

    // Loop through all slots of df
    for (int i = 1; i <= n; i++) {
      cur[0] = i;
      for (int j = 1; j <= m; j++) {
        // If the characters are the same, propogate diagonally from top left
        if (word1[i - 1] == word2[j - 1]) {
          cur[j] = prev[j - 1];
        }
        // If characters are different, take the minimum of the three options
        else {
          cur[j] = min(prev[j - 1], min(cur[j - 1], prev[j])) + 1;
        }
      }
      prev = cur;
    }

    return prev[m];
  }
};

class RecursiveSolution {
 public:
  int n, m;
  vector<vector<int>> track;
  int solve(int i, int j, string &a, string &b) {
    // At end of 1 string, return amount needed to add the rest of the other
    if (i == n) {
      return m - j;
    } else if (j == m) {
      return n - i;
    }

    // Call track if already calculated
    if (track[i][j] != -1) {
      return track[i][j];
    }

    // Same character needed means no change
    if (a[i] == b[j]) {
      return track[i][j] = solve(i + 1, j + 1, a, b);
    } else {
      // Insert, delete, or replace, check all possibilities
      int ins = 1 + solve(i, j + 1, a, b);
      int del = 1 + solve(i + 1, j, a, b);
      int rep = 1 + solve(i + 1, j + 1, a, b);
      return track[i][j] = min(ins, min(del, rep));
    }
  }
  int minDistance(string word1, string word2) {
    n = word1.size();
    m = word2.size();
    track.assign(n + 1, vector<int>(m + 1, -1));
    return solve(0, 0, word1, word2);
  }
};

class MySolution {
 public:
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();

    // track[i][j] represents distance between word1[:i] and word2[:j]
    vector<vector<int>> track(n + 1, vector<int>(m + 1));
    int ret = 0;

    for (int i = 1; i < n + 1; i++) {
      track[i][0] = i;
    }
    for (int j = 1; j < m + 1; j++) {
      track[0][j] = j;
    }

    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        // if the last characters are the same
        if (word1.at(i - 1) == word2.at(j - 1)) {
          track[i][j] = min(track[i - 1][j - 1],
                            min(track[i - 1][j], track[i][j - 1]) + 1);
        }
        // if the last characters are different
        else {
          track[i][j] = 1 + min(track[i - 1][j - 1],
                                min(track[i - 1][j], track[i][j - 1]));
        }
      }
    }

    // for (auto i : track) {
    //   for (auto j : i) {
    //     cout << j << " ";
    //   }
    //   cout << endl;
    // }

    return track[n][m];
  }
};