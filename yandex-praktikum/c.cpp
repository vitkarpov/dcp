#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int>>& m, int y, int x) {
  cout << m[y][x] << '\n';
}

void right(const vector<vector<int>>& m, int& y, int& x, int steps) {
  while (steps > 0) {
    print(m, y, x++);
    steps--;
  }
}

void down(const vector<vector<int>>& m, int& y, int& x, int steps) {
  while (steps > 0) {
    print(m, y++, x);
    steps--;
  }
}

void left(const vector<vector<int>>& m, int& y, int& x, int steps) {
  while (steps > 0) {
    print(m, y, x--);
    steps--;
  }
}

void up(const vector<vector<int>>& m, int& y, int& x, int steps) {
  while (steps > 0) {
    print(m, y--, x);
    steps--;
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> m(n, vector<int>(n));

  for (size_t y = 0; y < n; y++) {
    for (size_t x = 0; x < n; x++) {
      cin >> m[y][x];
    }
  }

  int y = n / 2;
  int x = n / 2;
  int base = -1;
  int calls = 0;

  while (calls < n * n) {
    if (base == -1) {
      up(m, y, x, 1);
    } else {
      right(m, y, x, base);
      down(m, y, x, base + 1);
      left(m, y, x, base + 1);
      up(m, y, x, base + 2);
    }
    base += 2;
    calls += 4 * (base + 1);
  }
  return 0;
}
