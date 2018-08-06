#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int getCountOfMaxIntersections(vector<int> starts, vector<int> ends) {
    int result = 0;
    int curr = 0;

    int i = 0;
    int j = 0;

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    while (i < starts.size() && j < ends.size()) {
        if (starts[i] < ends[j]) {
            curr++;
            result = max(result, curr);
            i++;
        } else {
            curr--;
            j++;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> starts(n);
    vector<int> ends(n);

    for (int i = 0; i < n; i++) {
        cin >> starts[i];
        cin >> ends[i];
    }

    cout << getCountOfMaxIntersections(starts, ends) << endl;
}
