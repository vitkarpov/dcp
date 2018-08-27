#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getMinString(const string & a, const string & b) {
    if (a.size() == b.size()) {
        return min(a, b);
    }
    return a.size() < b.size() ? a : b;
}

string getPalindrome(string s) {
    int n = s.size();
    // dp[start][len] refers to the palindrom which could be arranged
    // for the substring (start, len) from the origin string
    vector<vector<string>> dp(n + 1, vector<string>(n + 1));

    for (int start = 0; start < n; start++) {
        dp[start][1] = s[start];
    }

    for (int len = 2; len <= n; len++) {
        for (int start = 0; start < n + 1 - len; start++) {
            char first = s[start];
            char last = s[start + len - 1];

            if (first == last) {
                dp[start][len] = first + dp[start + 1][len - 2] + last;
            } else {
                string p1 = first + dp[start + 1][len - 1] + first;
                string p2 = last + dp[start][len - 1] + last;

                dp[start][len] = getMinString(p1, p2);
            }
        }
    }

    return dp[0][n];
}

int main() {
    string s;
    cin >> s;

    cout << getPalindrome(s) << endl;
}
