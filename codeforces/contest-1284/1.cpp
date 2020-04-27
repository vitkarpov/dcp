#include <stdio.h>
#include <vector>

using namespace std;

int el(const vector<int>& a, const vector<int>& b, int x) {
  return (x < a.size()) ? a[x] : b[x - a.size()];
}

bool check(const vector<int>& a, const vector<int>& b) {
  int len = a.size() + b.size();

  for (int i = 1; i < len; i++) {
    if (el(a, b, i - 1) < el(a, b, i)) {
      return true;
    }
  }
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> v(n);

  for (int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    v[i].resize(m);

    for (int j = 0; j < m; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (check(v[i], v[j])) {
        ans++;
      }
    }
  }
  printf("%d", ans);

  return 0;
}
