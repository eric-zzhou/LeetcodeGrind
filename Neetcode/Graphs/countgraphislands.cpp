#include <vector>
using namespace std;

class Solution {
 public:
  int find(vector<int>& par, int i) {
    while (i != par[i]) {
      par[i] = par[par[i]];
      i = par[i];
    }
    return i;
  }

  int dounion(vector<int>& ranks, vector<int>& par, int a, int b) {
    a = find(par, a);
    b = find(par, b);

    if (a == b) {
      return 0;
    }

    if (ranks[b] > ranks[a]) {
      par[a] = b;
      ranks[b] += ranks[a];
    } else {
      par[b] = a;
      ranks[a] += ranks[b];
    }
    return 1;
  }

  int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> ranks(n, 1);
    vector<int> par(n);
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }

    for (auto edge : edges) {
      n -= dounion(ranks, par, edge[0], edge[1]);
    }
    return n;
  }
};
