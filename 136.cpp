class Solution {
 public:
  int singleNumber(const vector<int>& nums) {
    int n = 0;

    for (auto v : nums) {
      n ^= v;
    }
    return n;
  }
};
