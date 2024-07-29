#include <vector>
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> track(n, 1);
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        track[j] += track[j - 1];
      }
    }
    return track[n - 1];
  }
};
