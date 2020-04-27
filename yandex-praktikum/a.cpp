#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (size_t i = 0; i < n - 2; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    while (a[i] != 0 && a[i] != i + 1) {
      swap(a[i], a[a[i] - 1]);
    }
  }
  for (size_t i = 0; i < n; i++) {
    if (a[i] == 0) {
      cout << i + 1 << ' ';
    }
  }
  cout << endl;
  return 0;
}
