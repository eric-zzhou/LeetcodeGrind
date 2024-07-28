#include <vector>
using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    vector<int> track(n + 1, 1);
    for (int i = 2; i < n + 1; i++) {
      track[i] = track[i - 2] + track[i - 1];
    }
    return track[n];
  }
};
