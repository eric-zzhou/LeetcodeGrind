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

  bool dounion(vector<int>& pars, vector<int>& ranks, int a, int b) {
    a = find(pars, a - 1);
    b = find(pars, b - 1);

    if (a == b) {
      return true;
    }

    if (ranks[b] > ranks[a]) {
      pars[a] = b;
      ranks[b] += ranks[a];
    } else {
      pars[b] = a;
      ranks[a] += ranks[b];
    }
    return false;
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> pars(n);
    vector<int> ranks(n, 1);
    for (int i = 0; i < n; i++) {
      pars[i] = i;
    }

    for (auto edge : edges) {
      if (dounion(pars, ranks, edge[0], edge[1])) {
        return edge;
      }
    }
    return {};
  }
};
