#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  unordered_set<int> visited;
  bool dfs(unordered_map<int, vector<int>> nes, int curr, int prev) {
    if (visited.find(curr) != visited.end()) {
      return false;
    }
    visited.insert(curr);

    for (auto ne : nes[curr]) {
      if (ne != prev) {
        if (!dfs(nes, ne, curr)) {
          return false;
        }
      }
    }
    return true;
  }

  bool validTree(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> nes;
    for (auto edge : edges) {
      nes[edge[0]].push_back(edge[1]);
      nes[edge[1]].push_back(edge[0]);
    }
    return dfs(nes, 0, -1) && (n == visited.size());
  }
};
