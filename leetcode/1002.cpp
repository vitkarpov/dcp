class Solution {
 public:
  vector<string> commonChars(const vector<string>& A) {
    int N = A.size();
    map<char, vector<int>> m;
    vector<string> result;

    for (char c = 'a'; c <= 'z'; c++) {
      m[c] = vector<int>(N, 0);
    }
    for (int i = 0; i < N; i++) {
      for (auto c : A[i]) {
        m[c][i]++;
      }
    }
    for (auto v : m) {
      int min = *min_element(v.second.begin(), v.second.end());

      for (int i = 0; i < min; i++) {
        result.push_back(string(1, v.first));
      }
    }

    return result;
  }
};
