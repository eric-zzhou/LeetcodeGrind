#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegs(numCourses, 0);
    vector<vector<int>> children(numCourses);
    for (auto prereq : prerequisites) {
      indegs[prereq[0]]++;
      children[prereq[1]].push_back(prereq[0]);
    }

    queue<int> q;
    vector<int> ret;
    for (int i = 0; i < indegs.size(); i++) {
      if (indegs[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      ret.push_back(curr);

      for (int child : children[curr]) {
        indegs[child]--;
        if (indegs[child] == 0) {
          q.push(child);
        }
      }
    }

    if (ret.size() != numCourses) {
      return {};
    } else {
      return ret;
    }
  }
};
