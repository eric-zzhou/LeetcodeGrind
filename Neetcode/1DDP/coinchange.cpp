#include <vector>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> track(amount + 1, 99999);
    track[0] = 0;
    for (int i = 1; i < amount + 1; i++) {
      for (int coin : coins) {
        if (coin <= i) {
          track[i] = min(track[i - coin] + 1, track[i]);
        }
      }
    }
    return (track[amount] != 99999) ? track[amount] : -1;
  }
};