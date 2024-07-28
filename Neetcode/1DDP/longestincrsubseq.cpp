#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> track(n + 1, -10001);
    int ret = 0;

    int temp;
    for (int n : nums) {
      if (n > track[ret]) {
        track[++ret] = n;
      } else {
        temp = ret;
        while (temp > 0 && n <= track[temp]) {
          temp--;
        }
        track[temp + 1] = min(track[temp + 1], n);
      }
    }
    return ret;
  }
};
