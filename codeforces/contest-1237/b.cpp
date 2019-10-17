#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> in(n + 1);
  vector<int> out(n + 1);
  vector<bool> visited(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> in[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> out[i];
  }
  int i = n;
  int j = n;
  int fines = 0;

  while (i > 1) {
    if (visited[out[j]]) {
      j--;
    } else {
      visited[in[i]] = true;
      if (in[i] != out[j]) {
        fines++;
      } else {
        j--;
      }
      i--;
    }
  }
  cout << fines << endl;
}
