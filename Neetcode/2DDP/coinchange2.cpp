// https://neetcode.io/problems/coin-change-ii
// https://leetcode.com/problems/coin-change-2/

#include <unordered_map>
#include <vector>
using namespace std;

class BetterSolution {
 public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();

    // dp vector
    vector<long long> prev(amount + 1, 0);

    // process first coin
    for (int i = 0; i <= amount; i++) {
      prev[i] = (i % coins[0] == 0);
    }

    // process remaining coins
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= amount; j++) {
        if (j >= coins[i]) {
          prev[j] += prev[j - coins[i]];
        }
      }
    }
    return prev[amount];
  }
};

// Cleaner version of solution written by me but slower for some reason
class MyRewritingSolution {
 public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<long long> track(amount + 1, 0);
    track[0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= amount; j++) {
        if (j >= coins[i]) {
          track[j] += track[j - coins[i]];
        }
      }
    }
    return track[amount];
  }
};

class MyDumbSolution {
 public:
  int change(int amount, vector<int>& coins) {
    unordered_map<int, int> track;
    track[0] = 1;
    int ret = 0;
    for (int c : coins) {
      unordered_map<int, int> temp;
      for (auto key : track) {
        int v = key.first;
        int t = key.first;
        while (t <= amount) {
          temp[t] += track[v];
          t += c;
        }
      }
      track = temp;
    }
    return track[amount];
  }
};
