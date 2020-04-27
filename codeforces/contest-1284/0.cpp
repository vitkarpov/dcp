#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> s(n);
  vector<string> t(m);

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }

  vector<string> r(n * m);
  int sp = 0;
  int tp = 0;

  for (int i = 0; i < n * m; i++) {
    r[i] = s[sp++ % n] + t[tp++ % m];
  }
  int q;
  cin >> q;
  vector<string> ans(q);
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    ans[i] = r[(x - 1) % (n * m)];
  }
  for (auto v : ans) {
    cout << v << endl;
  }
  return 0;
}
