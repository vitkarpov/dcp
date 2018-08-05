#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMinExceptJth(vector<int> dp, int k, int j) {
    int min = INT_MAX;

    for (int i = 0; i < k; i++) {
        if (i == j) {
            continue;
        }
        if (dp[i] < min) {
            min = dp[i];
        }
    }

    return min;
}

int getMinCost(vector<vector<int>> costs, int n, int k) {
    // dp[j] means minimum cost of painting the current row of buildings in j-th color
    // we have to update this data while moving each row of buildings in costs
    vector<int> dp(k);

    for (int i = 0; i < n; i++) {
        vector<int> next(k);

        for (int j = 0; j < k; j++) {
            // the next min costs have to be computed to not violate
            // the constraint about 2 neighbours of the same color
            next[j] = getMinExceptJth(dp, k, j) + costs[i][j];
        }

        dp = next;
    }

    return getMinExceptJth(dp, k, -1);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> costs(n, vector<int>(k));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> costs[i][j];
        }
    }

    cout << getMinCost(costs, n, k) << endl;
}
