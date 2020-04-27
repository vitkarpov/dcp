#include <iostream>

using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int x, y;

  if (e > f) {
    x = min(a, d);
    y = min(min(b, c), d - x);
  } else {
    y = min(min(b, c), d);
    x = min(a, d - y);
  }
  cout << (x * e + y * f) << endl;
}
