#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  cout << 3 * n + (k > n / 2 ? n - k : k - 1);
}
