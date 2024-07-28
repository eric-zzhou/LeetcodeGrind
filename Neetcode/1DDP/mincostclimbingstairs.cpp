#include <vector>
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> track(n + 1, 0);
    for (int i = 2; i < n + 1; ++i) {
      track[i] = min(track[i - 2] + cost[i - 2], track[i - 1] + cost[i - 1]);
    }
    return track[n];
  }
};
