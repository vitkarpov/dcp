#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

typedef vector<vector<bool>> TBoard;
typedef pair<int, int> TPoint;

bool canWalkThere(const TBoard & board, const TPoint & p, int yMax, int xMax) {
    return (
        // within bounds
        p.first >= 0 && p.first < xMax &&
        p.second >= 0 && p.second < yMax &&

        // has no obstacle
        board[p.second][p.first] == false
    );
}

vector<TPoint> getNextPoints(TBoard board, TPoint p, int yMax, int xMax) {
    vector<TPoint> result;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i * j == 0 && i != j) {
                TPoint next = {p.first + i, p.second + j};

                if (canWalkThere(board, next, yMax, xMax)) {
                    result.push_back(next);
                }
            }
        }
    }

    return result;
}

int getLenOfShortestPath(const TBoard & board, int n, int m, TPoint start, TPoint finish) {
    deque<pair<TPoint, int>> q = {{start, 0}};

    while (!q.empty()) {
        const auto tmp = q.front();
        q.pop_front();

        const TPoint curr = tmp.first;
        const int count = tmp.second;

        if (curr == finish) {
            return count;
        }

        auto next = getNextPoints(board, curr, n, m);

        for (auto it = next.begin(); it != next.end(); ++it) {
            q.push_back({*it, count + 1});
        }
    }

    return 0;
}

TPoint readPoint() {
    int x, y;
    cin >> x >> y;

    return {x, y};
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> board(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool tmp;
            cin >> tmp;
            board[i][j] = tmp;
        }
    }

    cout << getLenOfShortestPath(board, n, m, readPoint(), readPoint());
}
