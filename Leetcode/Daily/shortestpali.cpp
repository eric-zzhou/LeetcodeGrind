// https://leetcode.com/problems/shortest-palindrome
// 09/20/2024

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  // Function to find the shortest palindrome by adding characters in front of
  // the string
  string shortestPalindrome(string s) {
    // Create a reversed copy of the string s
    string str = s;
    reverse(str.begin(), str.end());

    // Combine the original string s, a separator '$', and the reversed string
    // The separator ensures no overlap between s and its reverse during LPS
    // calculation
    str = s + "$" + str;
    int n = str.size();  // Length of the combined string

    // LPS (Longest Prefix Suffix) array used for KMP (Knuth-Morris-Pratt)
    // pattern matching
    vector<int> LPS(n, 0);  // Initialize LPS array with zeros

    int i = 1;  // Pointer for the current character being matched
    int j = 0;  // Pointer for the length of the current longest prefix suffix

    // Calculate the LPS array for the combined string
    while (i < n) {
      if (str[i] == str[j]) {  // If characters match, extend the current prefix
        j++;                   // Increment length of the longest prefix suffix
        LPS[i] = j;            // Update LPS value for the current position
        i++;                   // Move to the next character
      } else {
        // If characters do not match
        if (j != 0) {
          // Set j to the previous LPS value (LPS[j - 1]) to try the next
          // possible prefix
          j = LPS[j - 1];
        } else {
          // If no prefix match is found, move to the next character
          i++;
        }
      }
    }

    // LPS[n - 1] gives the length of the longest palindromic prefix of s
    i = LPS[n - 1];  // Length of the longest prefix of s that is also a suffix
                     // of reversed s

    // Take the non-palindromic part of s (from index i onwards)
    str = s.substr(i, s.size() - i);

    // Reverse this non-palindromic substring to prepend it to s
    reverse(str.begin(), str.end());

    // Return the shortest palindrome by adding the reversed non-palindromic
    // part in front of s
    return str + s;
  }
};

// My stupid solution
class Solution {
 public:
  string shortestPalindrome(string s) {
    int sl = s.size();
    if (sl <= 1) {
      return s;
    }
    int l, r;
    string temp, even = "", odd = "";
    // cout << "sl:" << sl << endl;
    for (int i = sl / 2 - 1; i >= 0; i--) {
      // Check even and odd
      // Check odd
      // cout << " odd:" << endl;
      if (sl % 2 == 0 && i > 0) {
        l = i - 1, r = i + 1;
      } else {
        l = i, r = i + 2;
      }
      while (l >= 0 && s[l] == s[r]) {
        l--;
        r++;
        // cout << "   " << l << ", " << r << endl;
      }
      if (l == -1) {
        temp = s.substr(r, sl - r);
        reverse(temp.begin(), temp.end());
        odd = temp + s;
      }

      // Check even, add one to right right to be middle
      l = i, r = i + 1;
      // cout << "i: " << i << endl;
      // cout << " even:" << endl;
      while (l >= 0 && s[l] == s[r]) {
        l--;
        r++;
        // cout << "   " << l << ", " << r << endl;
      }
      if (l == -1) {
        temp = s.substr(r, sl - r);
        reverse(temp.begin(), temp.end());
        even = temp + s;
      }
      if (!even.empty() && !odd.empty()) {
        if (even.size() < odd.size()) {
          return even;
        } else {
          return odd;
        }
      } else if (!even.empty()) {
        return even;
      } else if (!odd.empty()) {
        return odd;
      }
    }
    temp = s.substr(1, sl - 1);
    reverse(temp.begin(), temp.end());
    return temp + s;
  }
};