// https://neetcode.io/problems/non-cyclical-number
// https://leetcode.com/problems/happy-number

class Solution {
 public:
  int proc(int n) {
    int ret = 0;
    while (n) {
      ret += (n % 10) * (n % 10);
      n = n / 10;
    }
    return ret;
  }
  bool isHappy(int n) {
    int fast = proc(proc(n)), slow = proc(n);
    while (fast != 1 && fast != slow) {
      fast = proc(proc(fast));
      slow = proc(slow);
    }
    return fast == 1;
  }
};