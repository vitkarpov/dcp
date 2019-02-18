#include <iostream>
#include <vector>

using namespace std;

int getSingle(const vector<int> & arr, int n) {
    int result = 0;
    int x, sum;

    for (int i = 0; i < 32; i++) {
        sum = 0;
        x = 1 << i;

        for (int j = 0; j < n; j++) {
            if (arr[j] & x) {
                sum++;
            }
        }

        // The bits with sum not multiple of 3 are
        // the bits of element with single occurrence
        if (sum % 3) {
            result |= x;
        }
    }

    return result;
}

void read(vector<int> & arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    read(arr, n);

    cout << getSingle(arr, n) << endl;
}
