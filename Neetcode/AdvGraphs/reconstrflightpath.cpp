// https://neetcode.io/problems/reconstruct-flight-path
// https://leetcode.com/problems/reconstruct-itinerary

#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string,
                  priority_queue<string, vector<string>, greater<string>>>
        mapi;

    // Populate the graph
    for (const auto& ticket : tickets) {
      mapi[ticket[0]].emplace(ticket[1]);
    }

    vector<string> v;
    stack<string> s;
    s.push("JFK");

    while (!s.empty()) {
      string h = s.top();
      if (mapi[h].empty()) {
        v.push_back(h);
        s.pop();
      } else {
        s.push(mapi[h].top());
        mapi[h].pop();
      }
    }

    reverse(v.begin(), v.end());
    return v;
  }
};

class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, multiset<string>> track;
    vector<string> ans;
    int n = tickets.size();

    for (int i = 0; i < n; i++) track[tickets[i][0]].insert(tickets[i][1]);

    stack<string> s;
    s.push("JFK");

    while (!s.empty()) {
      string check = s.top();

      if (track[check].size() == 0) {
        ans.push_back(check);
        s.pop();
      } else {
        auto it = track[check].begin();
        s.push(*it);
        track[check].erase(it);
      }
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};

class Solution {
 public:
  unordered_map<string, vector<string>> track;
  vector<string> ret;
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    for (auto t : tickets) {
      track[t[0]].push_back(t[1]);
    }
    for (auto& [_, destinations] : track) {
      sort(destinations.rbegin(), destinations.rend());
    }
    dfs("JFK");
    reverse(ret.begin(), ret.end());
    return ret;
  }

  void dfs(string curr) {
    vector<string>& temp = track[curr];
    while (!temp.empty()) {
      string next = temp.back();
      temp.pop_back();
      dfs(next);
    }
    ret.push_back(curr);
  }
};