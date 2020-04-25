#include <cassert>
#include <iostream>
#include <map>
#include <set>
using namespace std;

typedef pair<int, int> Point;
typedef int ShipId;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  map<ShipId, pair<set<Point>, int>> ships;
  map<Point, ShipId> points;

  ShipId currId = 0;

  while (k-- > 0) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    auto& item = ships[currId];

    for (int y = y1; y <= y2; y++) {
      Point p = {x1, y};
      item.first.insert(p);
      item.second = item.first.size();
      points[p] = currId;
    }
    for (int x = x1; x <= x2; x++) {
      Point p = {x, y1};
      item.first.insert(p);
      item.second = item.first.size();
      points[p] = currId;
    }
    currId++;
  }

  int s;
  cin >> s;

  int hit = 0;
  int wrecked = 0;

  while (s-- > 0) {
    int y, x;
    cin >> y >> x;
    Point p = {x, y};

    if (points.count(p)) {
      auto& v = ships[points[p]];
      if (v.first.size() == v.second) {
        hit++;
      }
      v.first.erase(p);
      if (v.first.size() == 0) {
        hit--;
        wrecked++;
      }
    }
  }
  cout << hit << ' ' << wrecked << endl;

  return 0;
}
