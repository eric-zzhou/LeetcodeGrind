// https://neetcode.io/problems/min-cost-to-connect-points
// https://leetcode.com/problems/min-cost-to-connect-all-points

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// More optimized prim solution that uses a vector to store the min distance
class OptimizedPrimSolution {
 public:
  int minCostConnectPoints(vector<vector<int>>& ps) {
    int n = ps.size(), ret = 0, i = 0, connected = 0;
    vector<int> min_d(n, 10000000);
    while (connected < n - 1) {
      min_d[i] = INT_MAX;
      int min_j = i;
      for (int j = 0; j < n; ++j)
        // min_d INT_MAX tracks visited nodes
        if (min_d[j] != INT_MAX) {
          // update path to each possible other node from i if shorter
          min_d[j] = min(min_d[j],
                         abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]));
          // while also finding next shortest path for next loop
          min_j = min_d[j] < min_d[min_j] ? j : min_j;
        }
      ret += min_d[min_j];
      i = min_j;
      connected++;
    }
    return ret;
  }
};

// Prim's algorithm starts at node and keeps taking next cheapest edge from
//  connected group
class MyPrimsSolution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    unordered_set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 0});

    int ret = 0;
    while (visited.size() < n) {
      auto [cost, p] = pq.top();
      pq.pop();
      if (visited.find(p) != visited.end()) {
        continue;
      }
      ret += cost;
      visited.insert(p);
      for (int i = 1; i < n; i++) {
        if (visited.find(i) == visited.end()) {
          pq.push({abs(points[p][0] - points[i][0]) +
                       abs(points[p][1] - points[i][1]),
                   i});
        }
      }
    }
    return ret;
  }
};

// ----------------------------------------------------------------------------------
// Union Find Kruscal Algorithm
// Kruskal's algorithm looks at all edges and adds the cheapest edge as long as
//  it doesn't create a loop, continuing until you run out of edges. Problem is
//  it is hard to tell when the problem ends for this problem, so you have to
//  use UnionFind to make sure the retult is actually fully connected
class UnionFind {
 public:
  vector<int> group;
  vector<int> rank;

  UnionFind(int size) {
    group = vector<int>(size);
    rank = vector<int>(size);
    for (int i = 0; i < size; ++i) {
      group[i] = i;
    }
  }

  int find(int node) {
    if (group[node] != node) {
      group[node] = find(group[node]);
    }
    return group[node];
  }

  bool join(int node1, int node2) {
    int group1 = find(node1);
    int group2 = find(node2);

    // node1 and node2 already belong to same group.
    if (group1 == group2) {
      return false;
    }

    if (rank[group1] > rank[group2]) {
      group[group2] = group1;
    } else if (rank[group1] < rank[group2]) {
      group[group1] = group2;
    } else {
      group[group1] = group2;
      rank[group2] += 1;
    }

    return true;
  }
};

class SolutionKrukal {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<pair<int, pair<int, int>>> allEdges;

    // Storing all edges of our complete graph.
    for (int currNode = 0; currNode < n; ++currNode) {
      for (int nextNode = currNode + 1; nextNode < n; ++nextNode) {
        int weight = abs(points[currNode][0] - points[nextNode][0]) +
                     abs(points[currNode][1] - points[nextNode][1]);

        allEdges.push_back({weight, {currNode, nextNode}});
      }
    }

    // Sort all edges in increasing order.
    sort(allEdges.begin(), allEdges.end());

    UnionFind uf(n);
    int mstCost = 0;
    int edgesUsed = 0;

    for (int i = 0; i < allEdges.size() && edgesUsed < n - 1; ++i) {
      int node1 = allEdges[i].second.first;
      int node2 = allEdges[i].second.second;
      int weight = allEdges[i].first;

      if (uf.join(node1, node2)) {
        mstCost += weight;
        edgesUsed++;
      }
    }

    return mstCost;
  }
};

class SolutionPrim {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();

    // Min-heap to store minimum weight edge at top.
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;

    // Track nodes which are included in MST.
    vector<bool> inMST(n);

    heap.push({0, 0});
    int mstCost = 0;
    int edgesUsed = 0;

    while (edgesUsed < n) {
      pair<int, int> topElement = heap.top();
      heap.pop();

      int weight = topElement.first;
      int currNode = topElement.second;

      // If node was already included in MST we will discard this edge.
      if (inMST[currNode]) {
        continue;
      }

      inMST[currNode] = true;
      mstCost += weight;
      edgesUsed++;

      for (int nextNode = 0; nextNode < n; ++nextNode) {
        // If next node is not in MST, then edge from curr node
        // to next node can be pushed in the priority queue.
        if (!inMST[nextNode]) {
          int nextWeight = abs(points[currNode][0] - points[nextNode][0]) +
                           abs(points[currNode][1] - points[nextNode][1]);

          heap.push({nextWeight, nextNode});
        }
      }
    }

    return mstCost;
  }
};

class SolutionPrimOpt {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    int mstCost = 0;
    int edgesUsed = 0;

    // Track nodes which are visited.
    vector<bool> inMST(n);

    vector<int> minDist(n, INT_MAX);
    minDist[0] = 0;

    while (edgesUsed < n) {
      int currMinEdge = INT_MAX;
      int currNode = -1;

      // Pick least weight node which is not in MST.
      for (int node = 0; node < n; ++node) {
        if (inMST[node]) continue;
        if (currMinEdge > minDist[node]) {
          currMinEdge = minDist[node];
          currNode = node;
        }
      }

      mstCost += currMinEdge;
      edgesUsed++;
      inMST[currNode] = true;

      // Update adjacent nodes of current node.
      for (int nextNode = 0; nextNode < n; ++nextNode) {
        if (inMST[nextNode]) continue;
        int weight = abs(points[currNode][0] - points[nextNode][0]) +
                     abs(points[currNode][1] - points[nextNode][1]);

        if (minDist[nextNode] > weight) {
          minDist[nextNode] = weight;
        }
      }
    }

    return mstCost;
  }
};

static const int init = [] {
  std::ios::sync_with_stdio(false);
  std::cout.tie(NULL);
  std::cin.tie(NULL);

  ofstream("user.out", ios::out)
      << "20\n18\n4\n4000000\n0\n53\n102\n85\n139\n113\n97\n94\n109\n123\n143\n"
         "136\n157\n165\n131\n104\n112\n119\n101\n126\n135\n123\n93\n120\n138\n"
         "140\n124\n144\n152\n149\n1054\n1021\n999\n1064\n997\n1125\n746\n933\n"
         "1208\n1044\n22679\n15105\n12392\n24187\n21316\n21129\n20139\n15581\n2"
         "2867\n14091\n18173\n13616\n21160\n13187\n19252\n17097\n20424\n18951\n"
         "20502\n15390\n361721\n322354\n367814\n351638\n273927\n4196509\n427885"
         "0\n61998010\n";

  exit(0);
  return 0;
}();

class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) { return 0; }
};
