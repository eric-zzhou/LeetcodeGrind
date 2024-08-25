// https://neetcode.io/problems/multiply-strings
// https://leetcode.com/problems/multiply-strings

#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    vector<int> ret(num1.length() + num2.length(), 0);
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (int i1 = 0; i1 < num1.length(); i1++) {
      for (int i2 = 0; i2 < num2.length(); i2++) {
        int digit = (num1[i1] - '0') * (num2[i2] - '0');
        ret[i1 + i2] += digit;
        ret[i1 + i2 + 1] += ret[i1 + i2] / 10;
        ret[i1 + i2] %= 10;
      }
    }

    stringstream result;
    int i = ret.size() - 1;
    while (i >= 0 && ret[i] == 0) {
      i--;
    }
    while (i >= 0) {
      result << ret[i--];
    }
    return result.str();
  }
};
