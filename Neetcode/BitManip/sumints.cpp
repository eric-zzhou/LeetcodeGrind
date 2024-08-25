// https://neetcode.io/problems/sum-of-two-integers
// https://leetcode.com/problems/sum-of-two-integers

class Solution {
 public:
  int getSum(int a, int b) {
    while (b) {
      int carry = a & b;
      a ^= b;
      b = (unsigned int)carry << 1;
    }
    return a;
  }
};
