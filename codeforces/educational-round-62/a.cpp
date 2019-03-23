#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = 0;
  int end = 0;

  for (int i = 1; i <= n; i++) {
    int curr;
    cin >> curr;
    end = max(end, curr);

    if (i == end) {
      ans++;
    }
  }
  cout << ans << endl;
}
