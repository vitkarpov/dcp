class Solution {
 public:
  // Time: O(n + m)
  // Space: O(m)
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<int, int> letters;

    for (auto v : magazine) {
      letters[v]++;
    }
    for (auto v : ransomNote) {
      letters[v]--;
      if (letters[v] < 0) {
        return false;
      }
    }
    return true;
  }
};
