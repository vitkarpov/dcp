#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int prev = 0;
  int lenCurr = 0;
  int lenPrev = 0;
  int halfAns = 0;

  for (int i = 0; i < n; i++) {
    int curr;
    cin >> curr;

    if (prev == 0 || prev == curr) {
      lenCurr++;
    } else {
      halfAns = max(halfAns, min(lenPrev, lenCurr));
      lenPrev = lenCurr;
      lenCurr = 1;
    }
    prev = curr;
  }

  halfAns = max(halfAns, min(lenPrev, lenCurr));
  cout << 2 * halfAns << endl;
}
