#include <vector>
#include <iostream>
#include <iomanip>
#include <deque>
#include <cmath>
#include <numeric>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<double>> levels(ceil(log2(n)) + 1);
  deque<int> q = {0};

  while (!q.empty()) {
    int root, left, right;
    double lifetime;
    cin >> root >> lifetime >> left >> right;
    int level = q.front();
    q.pop_front();
    levels[level].push_back(lifetime);
    if (left != -1) q.push_back(level + 1);
    if (right != -1) q.push_back(level + 1);
  }
  bool first = true;
  for (auto& row : levels) {
    if (row.size() == 0) {
      break;
    }
    if (!first) {
      cout << ' ';
    }
    cout << fixed << setprecision(2)
         << accumulate(row.begin(), row.end(), 0.0) / row.size();
    first = false;
  }
  cout << endl;
  return 0;
}
