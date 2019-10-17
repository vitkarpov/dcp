#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check(int x1, int x2, int x3) {
  return min(x1, x2) <= x3 && x3 <= max(x1, x2);
}

bool checkInside(vector<int> p1, vector<int> p2, vector<int>& v) {
  return check(p1[0], p2[0], v[0]) && check(p1[1], p2[1], v[1]) &&
         check(p1[2], p2[2], v[2]);
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> p(n);

  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;

    p[i] = {x, y, z, i + 1};
  }
  sort(p.begin(), p.end());

  for (int i = 0; i < n; i += 2) {
    // cout << p[i][3] << ' ' << p[i + 1][3] << endl;
  }
  for (int i = 0; i < n; i += 2) {
    auto p1 = p[i];
    auto p2 = p[i + 1];

    for (int j = i + 2; j < n; j++) {
      if (checkInside(p1, p2, p[j])) {
        cout << p1[0] << ' ' << p1[1] << ' ' << p1[2] << endl;
        cout << p2[0] << ' ' << p2[1] << ' ' << p2[2] << endl;
        cout << p[j][0] << ' ' << p[j][1] << ' ' << p[j][2] << endl;
      }
    }
  }
}
