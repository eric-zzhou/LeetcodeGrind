#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    if (s.at(0) == '0') {
      return 0;
    }

    int n = s.size();
    vector<int> track(n + 1, 0);
    track[0] = 1;
    track[1] = 1;
    for (int i = 1; i < n; i++) {
      if (s.at(i) == '0') {
        if (s.at(i - 1) == '1' || s.at(i - 1) == '2') {
          track[i + 1] = track[i - 1];
        } else {
          return 0;
        }
      } else {
        int temp = stoi(s.substr(i - 1, 2));
        if (10 < temp && temp <= 26) {
          track[i + 1] = track[i] + track[i - 1];
        } else {
          track[i + 1] = track[i];
        }
      }
    }
    return track[n];
  }
};
