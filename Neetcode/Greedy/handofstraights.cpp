// https://neetcode.io/problems/hand-of-straights
// https://leetcode.com/problems/hand-of-straights

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();

    // Edge cases
    if (n % groupSize != 0) {
      return false;
    }
    if (groupSize == 1) {
      return true;
    }

    int k = n / groupSize;
    int done = 0;

    // Sort the hand
    sort(hand.begin(), hand.end());

    // Create a queue to store the pairs
    queue<pair<int, int>> q;
    pair<int, int> fr;

    // Loop through the sorted hand
    for (int i = 0; i < n; i++) {
      // Start of new straight group
      if (q.empty() || q.front().first + 1 != hand[i]) {
        q.push({hand[i], 1});
        continue;
      }

      // Continue the straight group
      fr = q.front();
      q.pop();
      if (fr.second != groupSize - 1) {
        q.push({hand[i], fr.second + 1});
      } else {
        // Finish the straight group
        done++;
      }
    }
    // Check if all groups are finished
    return (done == k);
  }
};

class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    // Edge cases
    if (n % groupSize != 0) {
      return false;
    }
    if (groupSize == 1) {
      return true;
    }

    map<int, int> count;
    for (int card : hand) {
      count[card]++;
    }
    for (int i = 0; i < n / groupSize; i++) {
      int first = count.begin()->first;
      for (int j = 0; j < groupSize; j++) {
        if (count[first + j] == 0) {
          return false;
        }
        count[first + j]--;
        if (count[first + j] == 0) {
          count.erase(first + j);
        }
      }
    }
    return count.empty();
  }
};
