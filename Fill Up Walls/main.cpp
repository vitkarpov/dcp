#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> read(int n) {
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        cin >> result[i];
    }

    return result;
}

int getMaxPos(const vector<int> & heights) {
    int ans = 0;

    for (int i = 0; i < heights.size(); i++) {
        if (heights[i] > heights[ans]) {
            ans = i;
        }
    }

    return ans;
}

int getLeftCapacity(const vector<int> & heights, int maxPos) {
    int prevMax = heights[0];
    int result = 0;

    for (int i = 1; i < maxPos; i++) {
        result += max(0, prevMax - heights[i]);
        prevMax = max(prevMax, heights[i]);
    }

    return result;
}

int getRightCapacity(const vector<int> & heights, int maxPos) {
    int end = heights.size() - 1;
    int prevMax = heights[end];
    int result = 0;

    for (int i = end - 1; i > maxPos; i--) {
        result += max(0, prevMax - heights[i]);
        prevMax = max(prevMax, heights[i]);
    }

    return result;
}

int getFillingUpCapacity(const vector<int> & heights) {
    int maxPos = getMaxPos(heights);

    return getLeftCapacity(heights, maxPos) + getRightCapacity(heights, maxPos);
}

int main() {
    int n;
    cin >> n;

    vector<int> heights = read(n);

    cout << getFillingUpCapacity(heights) << endl;
}
