// https://neetcode.io/problems/swim-in-rising-water
// https://leetcode.com/problems/swim-in-rising-water

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  // dfs function to check if it's possible to reach the end given mid
  int dfs(vector<vector<int>>& g, int n, vector<vector<int>>& vis, int mid,
          int i, int j) {
    vis[i][j] = 1;

    // Successfully reached end
    if (i == n - 1 && j == n - 1) {
      return 1;
    }
    // Path is not possible
    if (g[i][j] > mid) {
      return 0;
    }

    // up
    if (i > 0) {
      if (!vis[i - 1][j] && g[i - 1][j] <= mid) {
        int ans = dfs(g, n, vis, mid, i - 1, j);
        if (ans == 1) {
          return 1;
        }
      }
    }
    // down
    if (i < n - 1) {
      if (!vis[i + 1][j] && g[i + 1][j] <= mid) {
        int ans = dfs(g, n, vis, mid, i + 1, j);
        if (ans == 1) {
          return 1;
        }
      }
    }
    // left
    if (j > 0) {
      if (!vis[i][j - 1] && g[i][j - 1] <= mid) {
        //  cout<<i<<j<<"left"<<endl;
        int ans = dfs(g, n, vis, mid, i, j - 1);
        if (ans == 1) {
          return 1;
        }
      }
    }

    // right
    if (j < n - 1) {
      if (!vis[i][j + 1] && g[i][j + 1] <= mid) {
        int ans = dfs(g, n, vis, mid, i, j + 1);
        if (ans == 1) {
          return 1;
        }
      }
    }
    return 0;
  }

  int swimInWater(vector<vector<int>>& g) {
    int e = 2500 - 1;  // extreme max value of grid
    int s = 0;         // min value of grid
    int n = g.size();
    int ret = 0;
    int t = 1;

    // Binary search
    while (s <= e) {
      int mid = (s + e) / 2;

      // visited grid
      vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));

      // dfs function call checks if it's possible
      int ans = dfs(g, n, vis, mid, 0, 0);
      if (ans == 1) {
        ret = mid;
        e = mid - 1;
        // cout << mid << "yes" << endl;
      } else {
        // cout << mid << "NO" << endl;
        s = mid + 1;
      }
    }
    return ret;
  }
};

class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int ret = grid[0][0];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    pq.push({ret, {0, 0}});

    while (!pq.empty()) {
      auto [t, p] = pq.top();
      pq.pop();
      auto [i, j] = p;
      grid[i][j] = INT_MAX;
      ret = max(ret, t);
      // cout << i << " " << j << " " << t << endl;
      if (i == n - 1 && j == m - 1) {
        return ret;
      }
      if (i < n - 1 && grid[i + 1][j] != INT_MAX) {
        pq.push({grid[i + 1][j], {i + 1, j}});
      }
      if (i > 0 && grid[i - 1][j] != INT_MAX) {
        pq.push({grid[i - 1][j], {i - 1, j}});
      }
      if (j < m - 1 && grid[i][j + 1] != INT_MAX) {
        pq.push({grid[i][j + 1], {i, j + 1}});
      }
      if (j > 0 && grid[i][j - 1] != INT_MAX) {
        pq.push({grid[i][j - 1], {i, j - 1}});
      }
    }
    return ret;
  }
};

class FirstSolution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int ret = grid[0][0];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    unordered_set<int> visited;
    pq.push({ret, {0, 0}});

    while (!pq.empty()) {
      auto [t, p] = pq.top();
      pq.pop();
      auto [i, j] = p;
      visited.insert(i * m + j);
      ret = max(ret, t);
      // cout << i << " " << j << " " << t << endl;
      if (i == n - 1 && j == m - 1) {
        return ret;
      }
      if (i < n - 1 && visited.find((i + 1) * m + j) == visited.end()) {
        pq.push({grid[i + 1][j], {i + 1, j}});
      }
      if (i > 0 && visited.find((i - 1) * m + j) == visited.end()) {
        pq.push({grid[i - 1][j], {i - 1, j}});
      }
      if (j < m - 1 && visited.find(i * m + j + 1) == visited.end()) {
        pq.push({grid[i][j + 1], {i, j + 1}});
      }
      if (j > 0 && visited.find(i * m + j - 1) == visited.end()) {
        pq.push({grid[i][j - 1], {i, j - 1}});
      }
    }
    return ret;
  }
};