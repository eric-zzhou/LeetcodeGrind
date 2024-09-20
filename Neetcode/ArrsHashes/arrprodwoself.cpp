// https://leetcode.com/problems/product-of-array-except-self/

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int lprod = 1;
    int rprod = 1;
    int n = nums.size();

    vector<int> ret(n, 1);
    for (int i = 0; i < n; i++) {
      ret[i] *= lprod;
      ret[n - i - 1] *= rprod;
      lprod *= nums[i];
      rprod *= nums[n - i - 1];
    }
    return ret;
  }
};

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int nprod = 1;
    int zero = -1;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        if (zero != -1) {
          zero = -2;
        } else {
          zero = i;
        }
      } else {
        nprod *= nums[i];
      }
    }

    vector<int> ret(nums.size(), 0);
    if (zero == -2) {
      return ret;
    }
    if (zero == -1) {
      for (int i = 0; i < n; i++) {
        ret[i] = nprod / nums[i];
      }
      return ret;
    }
    ret[zero] = nprod;
    return ret;
  }
};