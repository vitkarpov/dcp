#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  string line;
  getline(cin, line);
  getline(cin, line);
  istringstream iss(line);
  int v;
  while (iss >> v) {
    a.push_back(v);
  }
  sort(a.begin(), a.end());

  int min_diff = 30e5;
  int min_sum = n;

  for (size_t i = 0; i < a.size(); i++) {
    int left = i + 1;
    int right = a.size() - 1;

    while (left < right) {
      int sum = a[i] + a[left] + a[right];
      int diff = abs(sum - n);
      if (diff < min_diff) {
        min_diff = diff;
        min_sum = sum;
      }
      left++;
      right--;
    }
  }
  cout << min_sum << endl;
  return 0;
}
