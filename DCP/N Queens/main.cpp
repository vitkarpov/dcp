#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isValidQueenSet(vector<int> board) {
    int n = board.size();
    int lastQueenRow = n - 1;
    int lastQueenCol = board[n - 1];

    for (int row = 0; row < lastQueenRow; row++) {
        int col = board[row];
        int diff = abs(lastQueenCol - col);

        if (diff == 0 || diff == lastQueenRow - row) {
            return false;
        }
    }
    return true;
}

int nQueens(int n, vector<int> board) {
    if (board.size() == n) {
        return 1;
    }

    int count = 0;

    for (int col = 0; col < n; col++) {
        board.push_back(col);

        if (isValidQueenSet(board)) {
            count += nQueens(n, board);
        }

        board.pop_back();
    }

    return count;
}

int nQueens(int n) {
    vector<int> board;

    return nQueens(n, board);
}

int main() {
    int n;
    cin >> n;
    cout << nQueens(n) << endl;
}
