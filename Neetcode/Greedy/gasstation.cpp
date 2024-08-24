// https://neetcode.io/problems/gas-station
// https://leetcode.com/problems/gas-station

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // total gas < total cost means impossible
    if (accumulate(gas.begin(), gas.end(), 0) <
        accumulate(cost.begin(), cost.end(), 0)) {
      return -1;
    }

    // if it's possible there has to be a solution
    int total = 0;
    int ret = 0;

    // loop through the gas stations to see which spot is possible
    for (int i = 0; i < gas.size(); i++) {
      total += (gas[i] - cost[i]);
      if (total < 0) {
        total = 0;
        ret = i + 1;
      }
    }
    return ret;
  }
};

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int i = 0;
    int tank = 0, curr = gas[0];
    while (i < n * 2) {
      if (curr < cost[i % n]) {
        tank = i + 1;
        curr = gas[tank % n];
      } else {
        curr += gas[(i + 1) % n] - cost[i % n];
        if (i != tank && i % n == tank) {
          return tank;
        }
      }
      // cout << i << ": " << curr << ", " << tank << endl;
      i++;
    }
    return -1;
  }
};

// Too slow
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
      diff[i] = gas[i] - cost[i];
    }

    for (int i = 0; i < n; i++) {
      if (diff[i] < 0) {
        continue;
      }
      int curr = 0;
      for (int j = 0; j < n; j++) {
        curr += diff[(i + j) % n];
        if (curr < 0) {
          break;
        }
      }
      if (curr >= 0) {
        return i;
      }
    }
    return -1;
  }
};