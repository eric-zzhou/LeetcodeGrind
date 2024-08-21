// https://neetcode.io/problems/network-delay-time
// https://leetcode.com/problems/network-delay-time

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // track tracks shortest path/time from k to each node
    vector<int> track(n, INT_MAX);
    track[k - 1] = 0;

    // Create graph representation tracking index and weight
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < times.size(); i++) {
      graph[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
    }

    // Priority queue to go through shortest path
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, k - 1});

    // Dijkstra's algorithm
    while (!pq.empty()) {
      auto [cost, node] = pq.top();
      pq.pop();

      if (cost > track[node]) continue;

      for (const auto& path : graph[node]) {
        if (track[path.first] > cost + path.second) {
          track[path.first] = cost + path.second;
          pq.push({track[path.first], path.first});
        }
      }
    }

    // Loop through track to find furthest node
    int ret = INT_MIN;
    for (const int& i : track) {
      ret = max(ret, i);
    }
    return ret == INT_MAX ? -1 : ret;
  }
};

class MySolution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // check if possible using set
    vector<vector<pair<int, int>>> graph(n + 1);
    unordered_set<int> visited;
    for (auto& time : times) {
      graph[time[0]].push_back({time[1], time[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, k});
    visited.clear();

    int time = 0;
    while (!pq.empty() && visited.size() < n) {
      auto [curr_time, node] = pq.top();
      time = curr_time;
      pq.pop();
      visited.insert(node);
      for (auto& [neighbor, delay] : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
          pq.push({curr_time + delay, neighbor});
        }
      }
    }
    if (visited.size() != n) {
      return -1;
    }
    return time;
  }
};

class InitialMySolution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // check if possible using set
    vector<vector<pair<int, int>>> graph(n + 1);
    unordered_set<int> visited;
    for (auto& time : times) {
      graph[time[0]].push_back({time[1], time[2]});
      visited.insert(time[1]);
    }
    visited.insert(k);
    if (visited.size() != n) {
      return -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, k});
    visited.clear();

    int time = 0;
    while (!pq.empty() && visited.size() < n) {
      auto [curr_time, node] = pq.top();
      time = curr_time;
      pq.pop();
      visited.insert(node);
      for (auto& [neighbor, delay] : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
          pq.push({curr_time + delay, neighbor});
        }
      }
    }
    if (visited.size() != n) {
      return -1;
    }
    return time;
  }
};
