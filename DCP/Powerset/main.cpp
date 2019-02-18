#include <iostream>
#include <vector>

using namespace std;

void printPowerset(vector<vector<int>> powerset) {
    for (auto s : powerset) {
        for (auto i : s) cout << i << " ";
        cout << endl;
    }
}

vector<vector<int>> getPowerset(vector<int> set, int n) {
    // 2^n
    int len = 1 << n;
    vector<vector<int>> result(len);

    for (int i = 0; i < len; i++) {
        vector<int> item;

        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) > 0) {
                item.push_back(set[j]);
            }
        }
        result[i] = item;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> set(n);
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    printPowerset(getPowerset(set, n));
}
