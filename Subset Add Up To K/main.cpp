#include <iostream>
#include <vector>

using namespace std;

void read(vector<int> & arr, int n) {
    for (auto i = 0; i < n; i++) cin >> arr[i];
}

void print(const vector<int> & arr) {
    for (auto i : arr) cout << i << " ";
    cout << endl;
}

void collectPath(const vector<int> arr, const vector<vector<bool>> dp, int i, int k, vector<int> & path) {
    // if sum equals zero we've tracked the whole path
    if (k == 0) {
        return;
    }

    // if sum is not zero but we've seen all elements except the last one
    // it could complete the sum
    if (i == 0 && k > 0 && dp[0][k]) {
        path.push_back(arr[i]);
        return;
    }

    // the sum could be reached after ignoring the current element
    if (dp[i][k]) {
        collectPath(arr, dp, i - 1, k, path);
        return;
    }

    // the sum could be reached after considering the current element
    if (k >= arr[i] && dp[i][k - arr[i]]) {
        path.push_back(arr[i]);
        collectPath(arr, dp, i - 1, k - arr[i], path);
    }
}

vector<int> getSubsetAddUpToK(vector<int> arr, int n, int k) {
    // dp[i][j] means if there is a subset of arr[0..i-1] which adds up to j
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1));

    // there's always an empty subset for 0 sum
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    // there's no way to find empty subset for non-zero sum
    for (int i = 1; i <= k; i++) {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < arr[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    vector<int> path;
    collectPath(arr, dp, n, k, path);

    return path;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    read(arr, n);

    int k;
    cin >> k;

    print(getSubsetAddUpToK(arr, n - 1, k));
}
