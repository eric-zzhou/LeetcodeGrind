#include <vector>
using namespace std;

class Solution {
 public:
  void dfs(vector<vector<char>> &board, int i, int j) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] != 'O') {
      return;
    }
    board[i][j] = 'o';

    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j - 1);
    dfs(board, i, j + 1);
  }

  void solve(vector<vector<char>> &board) {
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++) {
      dfs(board, i, 0);
      dfs(board, i, m - 1);
    }

    for (int j = 1; j < m - 1; j++) {
      dfs(board, 0, j);
      dfs(board, n - 1, j);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'o') {
          board[i][j] = 'O';
        } else {
          board[i][j] = 'X';
        }
      }
    }
  }
};