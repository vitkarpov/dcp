#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  if (m == n) {
    cout << 0;
  } else if (m % n != 0) {
    cout << -1;
  } else {
    int moves = 0;
    int d = m / n;

    while (d != 1) {
      if (d % 2 == 0) {
        d /= 2;
      } else if (d % 3 == 0) {
        d /= 3;
      } else {
        moves = -1;
        break;
      }
      moves++;
    }
    cout << moves;
  }
}
