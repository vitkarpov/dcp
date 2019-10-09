class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int l = 0;
    int r = n - 1;

    while (l < r) {
      for (int i = l; i < r; i++) {
        int tmp = matrix[i][r];
        matrix[i][r] = matrix[l][i];

        int tmp2 = matrix[r][l + r - i];
        matrix[r][l + r - i] = tmp;

        int tmp3 = matrix[l + r - i][l];
        matrix[l + r - i][l] = tmp2;
        matrix[l][i] = tmp3;
      }
      l++;
      r--;
    }
  }
};
