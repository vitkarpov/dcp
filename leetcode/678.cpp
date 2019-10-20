class Solution {
 public:
  bool checkValidString(string s) {
    if (s.size() == 0) {
      return true;
    }
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        dp[i][i] = true;
      }
      if (i < n - 1 && (s[i] == '(' || s[i] == '*') &&
          (s[i + 1] == ')' || s[i + 1] == '*')) {
        dp[i][i + 1] = true;
      }
    }
    for (int k = 2; k < n; k++) {
      for (int i = 0; i < n - k; i++) {
        if (s[i] == '*' && dp[i + 1][i + k]) {
          dp[i][i + k] = true;
        } else if (s[i] == '(' || s[i] == '*') {
          for (int j = i + 1; j < i + k + 1; j++) {
            if ((s[j] == ')' || s[j] == '*') &&
                (j == i + 1 || dp[i + 1][j - 1]) &&
                (j == i + k || dp[j + 1][i + k])) {
              dp[i][i + k] = true;
            }
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};
