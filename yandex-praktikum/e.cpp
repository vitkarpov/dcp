#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

struct Point {
  int x, y;
};

bool operator==(const Point& a, const Point& b) {
  return a.x == b.x && a.y == b.y;
}

struct PointHash {
  size_t operator()(const Point& p) const {
    return (53 + hash<int>{}(p.y)) * 53 + hash<int>{}(p.x);
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  unordered_map<Point, int, PointHash> stores;

  while (m-- > 0) {
    int x, y, r;
    cin >> x >> y >> r;
    stores.insert({Point{x, y}, r});
  }
  int ans = 0;
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
      int curr = 0;
      for (auto& it : stores) {
        if (abs(it.first.x - x) + abs(it.first.y - y) <= it.second) {
          curr++;
        }
      }
      ans = max(ans, curr);
    }
  }
  cout << ans << endl;

  return 0;
}
