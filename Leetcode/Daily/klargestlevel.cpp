// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree
// 2024-10-22

#include <standard.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  long long kthLargestLevelSum(TreeNode *root, int k) {
    std::vector<std::int64_t> levelSums;
    int64_t maxSum = std::numeric_limits<int64_t>::min();
    int maxSumLevel = INT_MAX;

    if (root == nullptr) return 0;

    queue<TreeNode *> q;  // BFS
    q.push(root);

    int currentLevel = 1;
    while (!q.empty()) {
      // Sum all the nodes on the current level
      int64_t levelSum = 0;

      auto pending = q.size();
      while (pending--) {
        auto *node = q.front();
        q.pop();

        levelSum += node->val;

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }

      levelSums.emplace_back(levelSum);

      ++currentLevel;
    }

    if (levelSums.size() < k) return -1;

    std::nth_element(levelSums.begin(), levelSums.begin() + (k - 1),
                     levelSums.end(), std::greater<>());

    auto kth = *(levelSums.begin() + k - 1);
    return kth;
  }
};

class Solution {
 public:
  void dfs(vector<long long> &levels, TreeNode *root, int level) {
    if (level > (int)(levels.size()) - 1) {
      levels.push_back(0);
    }
    levels[level] += root->val;
    if (root->left != nullptr) {
      dfs(levels, root->left, level + 1);
    }
    if (root->right != nullptr) {
      dfs(levels, root->right, level + 1);
    }
  }
  long long kthLargestLevelSum(TreeNode *root, int k) {
    vector<long long> levels;
    dfs(levels, root, 0);
    sort(levels.begin(), levels.end());
    if (k > levels.size()) {
      return -1;
    }
    return levels[(int)(levels.size()) - k];
  }
};