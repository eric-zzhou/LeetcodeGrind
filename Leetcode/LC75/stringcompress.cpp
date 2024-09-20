// https://leetcode.com/problems/string-compression/

#include <vector>
using namespace std;

class Solution {
 public:
  int compress(vector<char>& chars) {
    int n = chars.size();
    if (n <= 1) {
      return n;
    }

    int l = 0, r = 0, ret = 0;
    while (l < n) {
      while (r < n && chars[r] == chars[l]) {
        r++;
      }
      // cout << ret << ", " << l << endl;
      chars[ret++] = chars[l];
      int curr = r - l;
      // cout << "curr " << curr << endl;
      if (curr > 1) {
        if (curr > 999) {
          chars[ret++] = '0' + curr / 1000;
          curr = curr % 1000;
          chars[ret++] = '0' + curr / 100;
          curr = curr % 100;
          chars[ret++] = '0' + curr / 10;
          curr = curr % 10;
          chars[ret++] = '0' + curr;
        } else if (curr > 99) {
          chars[ret++] = '0' + curr / 100;
          curr = curr % 100;
          chars[ret++] = '0' + curr / 10;
          curr = curr % 10;
          chars[ret++] = '0' + curr;
        } else if (curr > 9) {
          chars[ret++] = '0' + curr / 10;
          curr = curr % 10;
          chars[ret++] = '0' + curr;
        } else {
          chars[ret++] = '0' + curr;
        }
      }
      l = r;
    }
    return ret;
  }
};