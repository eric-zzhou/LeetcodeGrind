// https://neetcode.io/problems/minimum-interval-including-query
// https://leetcode.com/problems/minimum-interval-to-include-each-query

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> minInterval(vector<vector<int>>& intervals,
                          vector<int>& queries) {
    int n = intervals.size();
    int m = queries.size();

    // Sort intervals by start and queries with indices
    vector<pair<int, int>> qidx(m);
    for (int i = 0; i < m; i++) qidx[i] = {queries[i], i};
    sort(intervals.begin(), intervals.end());
    sort(qidx.begin(), qidx.end());

    //
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> ret(m, -1);

    int j = 0;
    for (auto [q, i] : qidx) {
      // cout << "q: " << q << " j: " << j;
      // if (j < n) cout << ", " << intervals[j][0] << ", " << intervals[j][1];
      // cout << endl;
      while (j < n && intervals[j][0] <= q) {
        if (q <= intervals[j][1]) {
          pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
        }
        j++;
      }
      // priority_queue<pair<int, int>, vector<pair<int, int>>,
      //                greater<pair<int, int>>>
      //     pq2 = pq;
      // while (!pq2.empty()) {
      //   cout << pq2.top().first << "," << pq2.top().second << "   ";
      //   pq2.pop();
      // }
      // cout << endl;
      while (!pq.empty() && pq.top().second < q) pq.pop();
      if (!pq.empty()) ret[i] = pq.top().first;
    }
    return ret;
  }
};

// Works but too slow
class Solution {
 public:
  vector<int> minInterval(vector<vector<int>>& intervals,
                          vector<int>& queries) {
    int n = intervals.size();
    int m = queries.size();
    vector<pair<int, int>> qidx(m);
    for (int i = 0; i < m; i++) {
      qidx[i] = {queries[i], i};
    }
    sort(intervals.begin(), intervals.end());
    sort(qidx.begin(), qidx.end());
    vector<int> ret(m, INT_MAX);

    int q = 0;
    for (auto i : intervals) {
      while (qidx[q].first < i[0]) {
        q++;
      }
      int l = i[0];
      int r = i[1];
      int tq = q;
      while (tq < m && qidx[tq].first <= r) {
        ret[qidx[tq].second] = min(ret[qidx[tq].second], r - l + 1);
        tq++;
      }
    }
    for (int i = 0; i < m; i++) {
      if (ret[i] == INT_MAX) {
        ret[i] = -1;
      }
    }
    return ret;
  }
};