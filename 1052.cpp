class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    vector<int> prefix(customers.size());

    for (int i = 0; i < customers.size(); i++) {
      prefix[i] = (i > 0 ? prefix[i - 1] : 0) + (grumpy[i] ? customers[i] : 0);
    }

    int addProfit = prefix[X - 1];

    for (int i = X; i < prefix.size(); i++) {
      addProfit = max(prefix[i] - prefix[i - X], addProfit);
    }

    int ans = 0;
    for (int i = 0; i < customers.size(); i++) {
      if (grumpy[i] == 0) {
        ans += customers[i];
      }
    }
    ans += addProfit;

    return ans;
  }
};
