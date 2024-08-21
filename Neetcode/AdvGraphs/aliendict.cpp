// https://neetcode.io/problems/foreign-dictionary
// https://leetcode.com/problems/alien-dictionary

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  // Tracks visited nodes, in set means visited at some point, True means
  //  visiting currently in path
  unordered_map<char, bool> visited;

  // Graph representation of each letter with children being letters that should
  //  be after
  unordered_map<char, vector<char>> graph;

  // Return string
  string ret;

  string foreignDictionary(vector<string>& words) {
    // Add all characters in words to graph to account for disconnected graph
    for (string word : words) {
      for (char ch : word) {
        graph[ch];
      }
    }

    // Graph construction, each node holds all letters that should come after
    for (int i = 0; i < words.size() - 1; i++) {
      int minlen = min(words[i].size(), words[i + 1].size());
      if (words[i].size() > words[i + 1].size() &&
          words[i].substr(0, minlen) == words[i + 1].substr(0, minlen)) {
        return "";
      }
      for (int j = 0; j < minlen; j++) {
        if (words[i][j] != words[i + 1][j]) {
          graph[words[i][j]].push_back(words[i + 1][j]);
          break;
        }
      }
    }

    // DFS on each letter
    for (auto& [k, v] : graph) {
      // Kill if cycle exists
      if (dfs(k)) {
        return "";
      }
    }

    // Reverse DFS to get correct order
    reverse(ret.begin(), ret.end());
    return ret;
  }

  bool dfs(char c) {
    // If visited before, return false, if currently visiting, return loop true
    if (visited.find(c) != visited.end()) {
      return visited[c];
    }

    // Mark as visiting
    visited[c] = true;

    // DFS on all children, propogate loop if found
    for (auto& next : graph[c]) {
      if (dfs(next)) {
        return true;
      }
    }

    // Mark as visited and not currently visiting
    visited[c] = false;

    // Postorder traversal to get correct reverse order
    ret += c;
    return false;
  }
};
