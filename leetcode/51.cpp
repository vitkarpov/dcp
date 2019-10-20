class Solution {
  vector<string> convert(const vector<int>& board) {
    int n = board.size();
    vector<string> ans;

    for (auto col : board) {
      string row(n, '.');
      row[col] = 'Q';
      ans.push_back(row);
    }
    return ans;
  }
  bool valid(const vector<int>& board) {
    int n = board.size();
    int queenY = n - 1;
    int queenX = board[n - 1];

    for (int y = 0; y < queenY; y++) {
      int x = board[y];
      int diff = abs(queenX - x);

      if (diff == 0 || diff == queenY - y) {
        return false;
      }
    }
    return true;
  }
  void helper(int n, vector<int>& board, vector<vector<string>>& ans) {
    if (board.size() == n) {
      ans.push_back(convert(board));
    }
    for (int col = 0; col < n; col++) {
      board.push_back(col);
      if (valid(board)) {
        helper(n, board, ans);
      }
      board.pop_back();
    }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<int> board;

    helper(n, board, ans);

    return ans;
  }
};
