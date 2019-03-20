#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> data;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    data.push_back({a, b});
  }

  int k;
  cin >> k;

  int read = 0;
  for (auto i : data) {
    if (k > i.first && k > i.second) {
      read++;
    } else {
      break;
    }
  }
  cout << n - read;
}
