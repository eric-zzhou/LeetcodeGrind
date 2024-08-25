// https://neetcode.io/problems/count-squares
// https://leetcode.com/problems/detect-squares

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// LeetCode Solution
class DetectSquares {
 public:
  // Given row, you get a map of column to count
  unordered_map<int, unordered_map<int, int>> points;
  DetectSquares() {}

  void add(vector<int> point) {
    int x = point[0], y = point[1];
    points[x][y]++;
  }

  int count(vector<int> point) {
    int x = point[0], y = point[1];

    int ret = 0;
    // Check all points in the same row
    for (auto& [py, count] : points[x]) {
      // Skip if same spot
      if (py == y) continue;

      // Grab side length and check if square exists
      int dy = y - py;

      // Check lower row for square
      if (points.find(x + dy) != points.end()) {
        unordered_map<int, int>& row = points[x + dy];
        if (row.find(y) != row.end() && row.find(y - dy) != row.end()) {
          ret += count * row[y] * row[y - dy];
        }
      }

      // Check upper row for square
      if (points.find(x - dy) != points.end()) {
        unordered_map<int, int>& row = points[x - dy];
        if (row.find(y) != row.end() && row.find(y - dy) != row.end()) {
          ret += count * row[y] * row[y - dy];
        }
      }
    }
    return ret;
  }
};

// LeetCode Solution: less efficient but faster
class DetectSquares {
 public:
  vector<pair<int, int>> points;
  int freq[1001][1001] = {};
  DetectSquares() {}

  void add(vector<int> point) {
    points.push_back({point[0], point[1]});
    freq[point[0]][point[1]] += 1;
  }

  int count(vector<int> point) {
    int ret = 0;
    int x = point[0], y = point[1];
    for (auto [x2, y2] : points) {
      if (abs(x - x2) != abs(y - y2)) continue;
      if (abs(x - x2) == 0 || abs(y - y2) == 0) continue;
      ret += freq[x][y2] * freq[x2][y];
    }
    return ret;
  }
};

// NeetCode Solution
class CountSquares {
 public:
  // Given row, you get a map of column to count
  unordered_map<int, unordered_map<int, int>> points;
  CountSquares() {}

  void add(vector<int> point) {
    int x = point[0], y = point[1];
    points[x][y]++;
  }

  int count(vector<int> point) {
    int x = point[0], y = point[1];
    // cout << "x: " << x << " y: " << y << endl;
    // for (auto& [px, row] : points) {
    //   for (auto& [py, count] : row) {
    //     // do (px, py): count
    //     cout << "(" << px << ", " << py << "): " << count << "     ";
    //   }
    //   cout << endl;
    // }

    int ret = 0;
    // Check all points in the same row
    for (auto& [py, count] : points[x]) {
      // Skip if same spot
      if (py == y) continue;

      // Grab side length and check if square exists
      int dy = y - py;

      // print py, dy, y, y - dy
      // cout << "\tpy: " << py << " dy: " << dy << " y: " << y
      //      << " y - dy: " << y - dy << endl;

      // Check lower row for square
      if (points.find(x + dy) != points.end()) {
        unordered_map<int, int>& row = points[x + dy];
        if (row.find(y) != row.end() && row.find(y - dy) != row.end()) {
          ret += count * row[y] * row[y - dy];
        }
      }

      // Check upper row for square
      if (points.find(x - dy) != points.end()) {
        unordered_map<int, int>& row = points[x - dy];
        if (row.find(y) != row.end() && row.find(y - dy) != row.end()) {
          ret += count * row[y] * row[y - dy];
        }
      }
    }
    // cout << endl;
    return ret;
  }
};