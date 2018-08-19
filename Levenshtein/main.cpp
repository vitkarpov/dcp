#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void print(vector<vector<int>> dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int getEditDistance(string a, string b) {
    int n = a.size();
    int m = b.size();

    // dp[i][j] is an edit distance to get a[0..i] from b[0..j] (or backward)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = max(i, j);
            } else {
                dp[i][j] = min(min(
                    // insert
                    dp[i - 1][j] + 1,
                    // delete
                    dp[i][j - 1] + 1
                ),
                    // replace
                    dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)
                );
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << getEditDistance(s1, s2) << endl;
}
