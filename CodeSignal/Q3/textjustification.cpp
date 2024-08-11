// https://leetcode.com/problems/text-justification

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    int curr_len = 0, start = 0, end = -1;
    for (string s : words) {
      if ((end - start + 1) + curr_len + s.size() <= maxWidth)
        curr_len += s.size(), end++;
      else {
        string sentence = words[start];
        int extra_space = maxWidth - curr_len,
            padding = extra_space / max(1, end - start);
        int extra = extra_space % max(1, end - start);
        for (int i = start + 1; i <= end; i++) {
          for (int j = 0; j < padding; j++) sentence += " ";
          if (extra) sentence += " ", extra--;
          sentence += words[i];
        }
        while (sentence.size() < maxWidth) sentence += " ";
        ans.push_back(sentence);
        start = end + 1, curr_len = s.size(), end++;
      }
    }
    string sentence = words[start];
    for (int i = start + 1; i <= end; i++) sentence += " " + words[i];
    while (sentence.size() < maxWidth) sentence += " ";
    ans.push_back(sentence);
    return ans;
  }
};

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;
    int count, spaces, ind = 0;
    vector<string> track;
    string temp = "";
    while (ind < words.size()) {
      track.push_back(words[ind]);
      count = words[ind++].size();
      while (ind < words.size() && count + words[ind].size() < maxWidth) {
        track.push_back(words[ind]);
        count += words[ind++].size() + 1;
      }

      if (ind == words.size() || track.size() == 1) {
        spaces = maxWidth - count;
        temp = track[0];
        for (int i = 1; i < track.size(); i++) {
          temp += " " + track[i];
        }
        string chunk(spaces, ' ');
        temp += chunk;
      } else {
        spaces = maxWidth - count + track.size() - 1;
        int next = spaces / (track.size() - 1);
        int extra = spaces - next * (track.size() - 1);
        temp = track[0];
        for (int i = 1; i < track.size(); i++) {
          int t = next;
          if (extra) {
            extra--;
            t++;
          }
          string chunk(t, ' ');
          temp += (chunk + track[i]);
          spaces -= t;
        }
      }
      track.clear();
      ret.push_back(temp);
    }
    return ret;
  }
};