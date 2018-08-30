#include <iostream>
#include <vector>

using namespace std;

vector<char> read(int n) {
    vector<char> result(n);

    for (int i = 0; i < n; i++) {
        cin >> result[i];
    }

    return result;
}

void partition(vector<char> & arr) {
    int start = 0;
    int middle = 0;
    int end = arr.size() - 1;

    while (middle <= end) {
        if (arr[middle] == 'R') {
            swap(arr[start], arr[middle]);
            start++;
            middle++;
        } else if (arr[middle] == 'G') {
            middle++;
        } else {
            swap(arr[middle], arr[end]);
            end--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> arr = read(n);

    partition(arr);

    for (auto c : arr) cout << c << " ";
    cout << endl;
}
