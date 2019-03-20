#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> people(n);
  unordered_map<int, int> people_index(n);
  vector<unordered_map<int, bool>> pairs(n + 1);
  vector<int> p;

  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d", &p);
    people[i] = p;
    people_index[p] = i;
  }

  int target = people[n - 1];

  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    pairs[u][v] = true;
    if (v == target) {
      p.push_back(u);
    }
  }

  vector<pair<int, int>> t;
  for (int i = 0; i < p.size(); i++) {
    t.push_back({people_index[p[i]], p[i]});
  }
  sort(t.begin(), t.end());

  int swaps = 0;
  unordered_map<int, bool> erasedPos;

  for (auto it = t.rbegin(); it != t.rend(); ++it) {
    int currPos = it->first;
    int curr = it->second;
    bool canSwap = true;

    for (int i = currPos + 1; i < n - 1; i++) {
      if (erasedPos[i]) {
        continue;
      }
      if (!pairs[curr][people[i]]) {
        canSwap = false;
        break;
      }
    }
    if (canSwap) {
      erasedPos[currPos] = true;
      swaps++;
    }
  }

  printf("%d", swaps);
}
