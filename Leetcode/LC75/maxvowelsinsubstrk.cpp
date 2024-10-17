// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <standard.h>
using namespace std;

class Solution {
 public:
  bool isVowel(char c) {
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
  }

  int maxVowels(string s, int k) {
    int ret = 0;
    int curr = 0;
    for (int i = 0; i < k; i++) {
      if (isVowel(s[i])) {
        curr++;
      }
    }
    ret = curr;
    for (int i = k; i <= s.size(); i++) {
      if (isVowel(s[i - k])) {
        curr--;
      }
      if (isVowel(s[i])) {
        curr++;
      }
      ret = max(ret, curr);
    }
    return ret;
  }
};