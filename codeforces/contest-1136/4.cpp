#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  freopen("foo", "r", stdin);
  int n, m;
  cin >> n >> m;
  vector<int> people(n);
  vector<int> was(n);
  vector<vector<int>> pairs(n);

  for (int i = 0; i < n; i++) {
    cin >> people[i];
    people[i]--;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    pairs[u].push_back(v);
  }

  reverse(people.begin(), people.end());
  int ans = 0;

  for (auto i : people) cout << i << ' ';
  cout << endl;

  was[people[0]] = 1;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    int cnt2 = 0;
    for (int to : pairs[people[i]]) {
      if (was[to]) cnt2++;
    }
    if (cnt == cnt2) {
      ans++;
    } else {
      was[people[i]] = 1;
      cnt++;
    }
  }

  cout << ans << endl;
}
