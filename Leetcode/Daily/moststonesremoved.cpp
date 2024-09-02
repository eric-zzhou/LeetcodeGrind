// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// 08/29/2024

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  unordered_map<int, vector<int>> rows;
  unordered_map<int, vector<int>> cols;
  vector<bool> visited;
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    int ret = 0;
    visited = vector<bool>(n, false);

    // Create graph
    for (int i = 0; i < n; i++) {
      rows[stones[i][0]].push_back(i);
      cols[stones[i][1]].push_back(i);
    }

    // Increment for each island
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        ret += dfs(stones, i) - 1;
      }
    }
    return ret;
  }

  // Dfs for island size
  int dfs(vector<vector<int>>& stones, int ind) {
    int ret = 1;
    visited[ind] = true;
    for (int i : rows[stones[ind][0]]) {
      if (!visited[i]) {
        ret += dfs(stones, i);
      }
    }
    for (int i : cols[stones[ind][1]]) {
      if (!visited[i]) {
        ret += dfs(stones, i);
      }
    }
    return ret;
  }
};