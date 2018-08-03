#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    deque<int> maxIndexes;

    for (int i = 0; i < k; i++) {
        while (maxIndexes.size() > 0 && arr[i] >= arr[maxIndexes.back()]) {
            maxIndexes.pop_back();
        }
        maxIndexes.push_back(i);
    }

    for (int i = k; i < n; i++) {
        cout << arr[maxIndexes.front()] << " ";

        while (maxIndexes.size() > 0 && maxIndexes.front() <= i - k) {
            maxIndexes.pop_front();
        }
        while (maxIndexes.size() > 0 && arr[maxIndexes.back()] <= arr[i]) {
            maxIndexes.pop_back();
        }
        maxIndexes.push_back(i);
    }
    cout << arr[maxIndexes.front()];
}
