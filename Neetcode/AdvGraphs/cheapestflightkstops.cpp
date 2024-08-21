// https://neetcode.io/problems/cheapest-flight-path
// https://leetcode.com/problems/cheapest-flights-within-k-stops

#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    vector<vector<pair<int, int>>> graph(n);
    for (const vector<int>& flight : flights) {
      graph[flight[0]].emplace_back(flight[1], flight[2]);
    }
    // creates distance tracking dynamic programming table, cities x k + 2
    //  (k + 2 = total cities visited since including src and dst)
    // tracks shortest distance from src to each city with k stops
    vector<vector<int>> dist(graph.size(), vector<int>(k + 2, INT_MAX));

    // priority queue to sorting by distance
    using T = tuple<int, int, int>;  // (distance , node, stops)
    priority_queue<T, vector<T>, greater<>> pq;

    // initialize source node
    dist[src][k + 1] = 0;
    pq.emplace(dist[src][k + 1], src, k + 1);

    while (!pq.empty()) {
      auto [d, u, stops] = pq.top();
      pq.pop();
      // if destination reached, return distance (since shortest is first)
      if (u == dst) return d;
      // if k stops used or distance is larger than current, skip
      if (stops == 0 || d > dist[u][stops]) continue;

      // for each neighbor, update distance if shorter
      for (auto& [v, w] : graph[u])
        if (d + w < dist[v][stops - 1]) {
          dist[v][stops - 1] = d + w;
          pq.emplace(dist[v][stops - 1], v, stops - 1);
        }
    }
    return -1;
  }
};

// Very slow solution
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (vector<int> flight : flights) {
      graph[flight[0]].emplace_back(flight[1], flight[2]);
    }

    // cost, node, length
    queue<vector<int>> q;
    vector<int> track(n, INT_MAX);
    q.push({0, src, 0});
    while (!q.empty()) {
      vector<int> top = q.front();
      q.pop();
      if (top[2] > k + 1) {
        break;
      }
      if (top[0] < track[top[1]]) {
        track[top[1]] = top[0];
        for (pair<int, int> next : graph[top[1]]) {
          q.push({top[0] + next.second, next.first, top[2] + 1});
        }
      }
    }
    return (track[dst] == INT_MAX) ? -1 : track[dst];
  }
};

// TOO SLOW
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (vector<int> flight : flights) {
      graph[flight[0]].push_back({flight[1], flight[2]});
    }

    int ret = INT_MAX;
    // cost, node, length
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> track(n, INT_MAX);
    pq.push({0, src, 0});
    while (!pq.empty()) {
      vector<int> top = pq.top();
      pq.pop();

      if (top[2] > k + 1) {
        continue;
      }
      if (top[1] == dst) {
        ret = top[0];
        break;
      }
      for (pair<int, int> next : graph[top[1]]) {
        if (top[0] + next.second >= track[next.first]) {
          continue;
        }
        pq.push({top[0] + next.second, next.first, top[2] + 1});
      }
    }
    return (ret == INT_MAX) ? -1 : ret;
  }
};
