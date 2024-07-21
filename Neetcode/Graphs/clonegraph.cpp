#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
 public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class BestSolution {
 public:
  unordered_map<Node *, Node *> track;
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return nullptr;
    }

    if (track.find(node) == track.end()) {
      track[node] = new Node(node->val);
      for (auto n : node->neighbors) {
        track[node]->neighbors.push_back(cloneGraph(n));
      }
    }
    return track[node];
  }
};

class DecentSolution {
 public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return nullptr;
    }

    unordered_map<Node *, Node *> track;
    track[node] = new Node(node->val);
    deque<Node *> dq;
    dq.push_back(node);

    while (!dq.empty()) {
      Node *curr = dq.front();
      dq.pop_front();
      for (Node *n : curr->neighbors) {
        if (track.find(n) == track.end()) {
          track[n] = new Node(n->val);
          dq.push_back(n);
        }
        track[curr]->neighbors.push_back(track[n]);
      }
    }
    return track[node];
  }
};