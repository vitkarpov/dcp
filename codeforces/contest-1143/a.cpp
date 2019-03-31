#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int lastL = 0;
  int lastR = 0;

  for (int i = 1; i <= n; i++) {
    int d;
    cin >> d;

    if (d == 0) {
      lastL = i;
    } else if (d == 1) {
      lastR = i;
    } else {
      assert(false);
    }
  }

  cout << min(lastL, lastR) << endl;
}
