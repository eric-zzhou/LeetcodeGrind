// https://leetcode.com/problems/path-with-maximum-probability/
// 08/27/2024

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Dynamic Programming Solution
class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start_node,
                        int end_node) {
    vector<double> track(n);
    track[start_node] = 1.0;
    for (int i = 0; i < n; ++i) {
      bool change = false;
      for (int j = 0; j < n; ++j) {
        int a = edges[j][0], b = edges[j][1];
        double p = succProb[j];
        if (track[a] * p > track[b]) {
          track[b] = track[a] * p;
          change = true;
        }
        if (track[b] * p > track[a]) {
          track[a] = track[b] * p;
          change = true;
        }
      }
      if (!change) break;
    }
    return track[end_node];
  }
};

// Graph Based Greedy Algorithm Solution
class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start_node,
                        int end_node) {
    unordered_map<int, vector<pair<int, double>>> graph;
    priority_queue<pair<double, int>> pq;

    // Build graph
    for (int i = 0; i < n; i++) {
      int a = edges[i][0];
      int b = edges[i][1];

      graph[a].emplace_back(b, succProb[i]);
      graph[b].emplace_back(a, succProb[i]);
    }

    pq.emplace(1.0, start_node);
    while (!pq.empty()) {
      auto [prob, node] = pq.top();
      pq.pop();

      if (node == end_node) {
        return prob;
      }

      for (auto& [n2, p2] : graph[node]) {
        if (graph.find(n2) != graph.end()) {
          pq.push({prob * p2, n2});
        }
      }
      graph.erase(node);
    }
    return 0;
  }
};

class SolutionWPrints {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start_node,
                        int end_node) {
    unordered_map<int, vector<pair<int, double>>> graph;
    priority_queue<pair<double, int>> pq;

    // Build graph
    for (int i = 0; i < n; i++) {
      int a = edges[i][0];
      int b = edges[i][1];

      graph[a].emplace_back(b, succProb[i]);
      graph[b].emplace_back(a, succProb[i]);
    }
    // // Print out graph in good format
    // cout << "graph: ";
    // for (auto& [node, neighbors] : graph) {
    //   cout << node << " -> ";
    //   for (auto& [n2, p2] : neighbors) {
    //     cout << "(" << n2 << "," << p2 << "), ";
    //   }
    //   cout << endl;
    // }

    pq.emplace(1.0, start_node);
    unordered_set<int> visited;
    while (!pq.empty()) {
      // // Clone and print pq in this format [(prob,node), (prob,node), ...]
      // cout << "pq: ";
      // priority_queue<pair<double, int>> pq2 = pq;
      // while (!pq2.empty()) {
      //   auto [prob, node] = pq2.top();
      //   cout << "(" << prob << "," << node << "), ";
      //   pq2.pop();
      // }
      // cout << endl;

      auto [prob, node] = pq.top();
      pq.pop();
      visited.insert(node);

      if (node == end_node) {
        return prob;
      }

      // cout << "node: " << node << ", prob: " << prob << endl;
      for (auto& [n2, p2] : graph[node]) {
        if (visited.find(n2) == visited.end()) {
          // cout << "\tn2: " << n2 << ", p2: " << p2 << endl;
          pq.push({prob * p2, n2});
        }
      }
    }
    return 0;
  }
};
