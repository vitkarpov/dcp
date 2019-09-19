class Solution {
 public:
  void duplicateZeros(const vector<int>& arr) {
    int k = 0;

    for (auto v : arr) {
      if (v == 0) k++;
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
      if (i + k < arr.size()) {
        arr[i + k] = arr[i];
      }
      if (arr[i] == 0) {
        k--;
        if (i + k < arr.size()) {
          arr[i + k] = 0;
        }
      }
    }
  }
}
