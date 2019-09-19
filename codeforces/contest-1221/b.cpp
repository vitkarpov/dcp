#include <iostream>
#include <vector>

using namespace std;

bool inBoard(int x, int y, int n) { return x >= 0 && x < n && y >= 0 && y < n; }

// 1 - w
// -1 - b
void walk(vector<vector<int>>& board, int x, int y, int n) {
  int type = board[y][x];
  vector<pair<int, int>> dirs;

  dirs.push_back({x + 2, y + 1});
  dirs.push_back({x + 2, y - 1});
  dirs.push_back({x - 2, y + 1});
  dirs.push_back({x - 2, y - 1});
  dirs.push_back({x + 1, y + 2});
  dirs.push_back({x + 1, y - 2});
  dirs.push_back({x - 1, y + 2});
  dirs.push_back({x - 1, y - 2});

  for (auto v : dirs) {
    if (inBoard(v.first, v.second, n) && board[v.second][v.first] == 0) {
      board[v.second][v.first] = -type;
      walk(board, v.first, v.second, n);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> board(n, vector<int>(n));
  int sx = 0;
  int sy = 0;

  board[sy][sx] = 1;
  walk(board, sx, sy, n);

  for (auto i : board) {
    for (auto j : i) {
      if (j > 0) {
        cout << "B";
      } else if (j <= 0) {
        cout << "W";
      }
    }
    cout << endl;
  }
}
