// https://leetcode.com/problems/number-of-provinces/
#include <vector>
using namespace std;

class Solution {
 public:
  int find(vector<int>& pars, int i) {
    while (i != pars[i]) {
      pars[i] = pars[pars[i]];
      i = pars[i];
    }
    return i;
  }

  int doUnion(vector<int>& pars, vector<int>& ranks, int a, int b) {
    a = find(pars, a);
    b = find(pars, b);
    if (a == b) {
      return 0;
    }
    if (ranks[b] > ranks[a]) {
      pars[a] = b;
      ranks[b] += ranks[a];
    } else {
      pars[b] = a;
      ranks[a] += ranks[b];
    }
    return 1;
  }

  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> pars(n);
    for (int i = 0; i < n; i++) {
      pars[i] = i;
    }

    vector<int> ranks(n, 1);
    int ret = n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (isConnected[i][j] == 1) {
          ret -= doUnion(pars, ranks, i, j);
        }
      }
    }
    return ret;
  }
};