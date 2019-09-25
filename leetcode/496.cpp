class Solution {
 public:
  vector<int> nextGreaterElement(const vector<int>& nums1,
                                 const vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> m;

    for (auto v : nums2) {
      while (!s.empty() && s.top() < v) {
        m[s.top()] = v;
        s.pop();
      }
      s.push(v);
    }
    while (!s.empty()) {
      m[s.top()] = -1;
      s.pop();
    }
    vector<int> res;
    for (auto v : nums1) {
      res.push_back(m[v]);
    }
    return res;
  }
};
