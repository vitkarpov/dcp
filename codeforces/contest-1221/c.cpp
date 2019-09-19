#include <iostream>
#include <algorithm>

using namespace std;

int teams(int c, int m, int x) {
  int y = min(c, m);
  int l = max(c, m);

  if (y <= x) {
    return y;
  }
  if (2 * y <= l + x) {
    return y;
  }
  return (c + m + x) / 3;
}

int main() {
  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int c, m, x;
    cin >> c >> m >> x;

    cout << teams(c, m, x) << endl;
  }
}
