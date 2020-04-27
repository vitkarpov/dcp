#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  string s;
  getline(cin, s);

  for (size_t u = 0; u < n; u++) {
    getline(cin, s);
    stringstream ss(s);
    int v;
    while (ss >> v) {
      g[u].push_back(v);
    }
  }

  vector<int> side(n, -1);
  bool ans = true;
  queue<int> q;

  for (int st = 0; st < n; ++st) {
    if (side[st] == -1) {
      q.push(st);
      side[st] = 0;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
          if (side[u] == -1) {
            side[u] = side[v] ^ 1;
            q.push(u);
          } else {
            ans &= side[u] != side[v];
          }
        }
      }
    }
  }
  cout << (ans ? "True" : "False") << endl;

  return 0;
}
