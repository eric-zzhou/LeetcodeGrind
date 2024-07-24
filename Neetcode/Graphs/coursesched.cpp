#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// Uses Kahn's algorithm
class BetterSolution {
 public:
  bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    int ans = 0;

    for (auto x : prerequisites) {
      adj[x[0]].push_back(x[1]);
      indegree[x[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      auto t = q.front();
      ans++;
      q.pop();

      for (auto x : adj[t]) {
        indegree[x]--;
        if (indegree[x] == 0) {
          q.push(x);
        }
      }
    }
    return ans == n;
  }
};

class MySolution {
 public:
  unordered_set<int> visited;
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> track(numCourses);
    for (auto pre : prerequisites) {
      track[pre[0]].push_back(pre[1]);
    }

    for (int i = 0; i < numCourses; i++) {
      if (!dfs(track, i)) {
        return false;
      }
    }
    return true;
  }

  bool dfs(vector<vector<int>>& track, int i) {
    if (visited.find(i) != visited.end()) {
      return false;
    }

    visited.insert(i);
    for (auto pre : track[i]) {
      if (!dfs(track, pre)) {
        return false;
      }
    }
    track[i] = {};
    visited.erase(i);
    return true;
  }
};
