#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<int>& nums) {
  int sum = 0;

  for (auto n : nums) {
    if (n < 4096) {
      sum += n;
    }
    if (sum >= 2048) {
      return true;
    }
  }
  return false;
}

int main() {
  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int j = 0; j < n; j++) {
      cin >> nums[j];
    }

    if (check(nums)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
}
