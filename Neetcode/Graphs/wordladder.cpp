#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // build the set for more efficient search
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.count(endWord)) return 0;

    // initialize the 2-end BFS
    queue<string> q1{{beginWord}};
    queue<string> q2{{endWord}};
    unordered_map<string, int> m1;  // store the distance from beginWord
    unordered_map<string, int> m2;  // store the distance from endWord
    m1[beginWord] = 0;
    m2[endWord] = 0;

    // Double BFS
    while (!q1.empty() && !q2.empty()) {
      int t = q1.size() <= q2.size() ? extend(m1, m2, q1, words)
                                     : extend(m2, m1, q2, words);
      if (t != -1) return t + 1;
    }
    return 0;
  }

  // extend the current word using BFS
  int extend(unordered_map<string, int>& m1, unordered_map<string, int>& m2,
             queue<string>& q, unordered_set<string>& words) {
    for (int i = q.size(); i > 0; --i) {
      string s = q.front();
      int step = m1[s];
      q.pop();
      for (int j = 0; j < s.size(); ++j) {
        char ch = s[j];
        for (char k = 'a'; k <= 'z'; ++k) {
          s[j] = k;
          if (!words.count(s) || m1.count(s)) continue;
          if (m2.count(s)) return step + 1 + m2[s];
          m1[s] = step + 1;
          q.push(s);
        }
        s[j] = ch;
      }
    }
    return -1;
  }
};

class MidSolution {
 public:
  int ladderLength(string startWord, string targetWord,
                   vector<string>& wordList) {
    queue<pair<string, int>> q;
    q.push({startWord, 1});

    // build the set for more efficient search
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);

    // BFS
    while (!q.empty()) {
      string word = q.front().first;
      int ret = q.front().second;
      q.pop();

      if (word == targetWord) return ret;

      // change the word to all possibilities
      for (int i = 0; i < word.size(); i++) {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++) {
          word[i] = ch;
          if (st.find(word) != st.end()) {
            st.erase(word);
            q.push({word, ret + 1});
          }
        }
        word[i] = original;
      }
    }
    return 0;
  }
};

class BadSolution {
 public:
  unordered_map<string, vector<string>> graph;
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int m = beginWord.size();
    bool exists = false;

    // build the graph using * trie technique
    for (string word : wordList) {
      if (word == endWord) {
        exists = true;
      }
      for (int j = 0; j < m; ++j) {
        graph[word.substr(0, j) + "*" + word.substr(j + 1, m - j - 1)]
            .push_back(word);
      }
    }

    // endWord is not in the wordList
    if (!exists) {
      return 0;
    }

    // BFS
    int ret = 1;
    queue<string> q({beginWord});
    unordered_set<string> visited({beginWord});
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        string curr = q.front();
        q.pop();
        if (curr == endWord) {
          return ret;
        }
        for (int j = 0; j < m; ++j) {
          for (string ne :
               graph[curr.substr(0, j) + "*" + curr.substr(j + 1, m - j - 1)]) {
            if (visited.find(ne) == visited.end()) {
              q.push(ne);
              visited.insert(ne);
            }
          }
        }
      }
      ret += 1;
    }

    return 0;
  }
};
