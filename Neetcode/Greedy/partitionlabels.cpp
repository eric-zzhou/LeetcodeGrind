// https://neetcode.io/problems/partition-labels
// https://leetcode.com/problems/partition-labels

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    // Track last index of each character
    vector<int> last(26, -1);
    int n = s.size();
    for (int i = 0; i < n; i++) {
      last[s[i] - 'a'] = i;
    }

    // Find partition sizes
    vector<int> ret;
    int size = 0;
    int maxLast = 0;

    // Iterate through string
    for (int i = 0; i < n; i++) {
      // Reach the end of current partition
      if (maxLast < i) {
        ret.push_back(size);
        size = 0;
      }
      maxLast = max(maxLast, last[s[i] - 'a']);
      size++;
    }
    ret.push_back(size);
    return ret;
  }
};

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    int n = s.size();
    vector<int> ret;
    vector<int> last(26, -1);
    for (int i = 0; i < n; i++) {
      last[s[i] - 'a'] = i;
    }
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
      end = max(end, last[s[i] - 'a']);
      if (i == end) {
        ret.push_back(end - start + 1);
        start = end + 1;
      }
    }
    return ret;
  }
};
