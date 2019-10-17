#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  bool ceil = true;
  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (auto n : v) {
    if (n % 2 != 0) {
      if (ceil) {
        cout << (n - 1) / 2 << endl;
      } else {
        cout << (n + 1) / 2 << endl;
      }
      ceil = !ceil;
    } else {
      cout << n / 2 << endl;
    }
  }
}
