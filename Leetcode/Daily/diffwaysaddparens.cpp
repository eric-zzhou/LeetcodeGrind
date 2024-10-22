// https://leetcode.com/problems/different-ways-to-add-parentheses
// 09/19/2024

#include <standard.h>

#include <cstdlib>
using namespace std;

class Solution {
 public:
  unordered_map<string, vector<int>> memo;
  vector<int> diffWaysToCompute(string expression) {
    if (memo.find(expression) != memo.end()) {
      return memo[expression];
    }
    vector<int> ret;
    char curr;
    vector<int> lefts, rights;
    for (int i = 0; i < expression.size(); i++) {
      curr = expression[i];
      if (curr == '+' || curr == '-' || curr == '*') {
        lefts = diffWaysToCompute(expression.substr(0, i));
        rights = diffWaysToCompute(expression.substr(i + 1));
        for (int l : lefts) {
          for (int r : rights) {
            if (curr == '+') {
              ret.push_back(l + r);
            } else if (curr == '-') {
              ret.push_back(l - r);
            } else {
              ret.push_back(l * r);
            }
          }
        }
      }
    }
    if (ret.empty()) {
      ret.push_back(stoi(expression));
    }
    memo[expression] = ret;
    return ret;
  }
};