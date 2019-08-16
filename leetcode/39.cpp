#include <vector>

using namespace std;

class Solution {
 private:
  void dfs(const vector<int>& candidates, int start, int target,
           vector<int>& path, vector<vector<int>>& result) {
    for (int i = start; i < candidates.size(); i++) {
      if (path.size() > 0 && i < path.back()) {
        continue;
      }

      int next = target - candidates[i];
      path.push_back(i);
      if (next > 0) {
        dfs(candidates, i, next, path, result);
      } else if (next == 0) {
        vector<int> values;
        for (auto j : path) {
          values.push_back(candidates[j]);
        }
        result.push_back(values);
      }
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(const vector<int>& candidates,
                                     int target) {
    vector<vector<int>> result;
    vector<int> path;

    dfs(candidates, 0, target, path, result);

    return result;
  }
};
