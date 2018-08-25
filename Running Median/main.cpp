#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

bool maxCmp(const float & a, const float & b) {
    return a < b;
}

bool minCmp(const float & a, const float & b) {
    return a > b;
}

void rebalanceHeaps(deque<float> & left, deque<float> & right) {
    if (left.size() > right.size()) {
        right.push_back(left.front());
        left.pop_front();
    } else {
        left.push_back(right.front());
        right.pop_front();
    }
    push_heap(right.begin(), right.end(), minCmp);
    push_heap(left.begin(), left.end(), maxCmp);
}

float getRunningMedian(float n, deque<float> & left, deque<float> & right) {
    if (left.empty() || n < left.front()) {
        left.push_back(n);
    } else {
        right.push_back(n);
    }
    push_heap(right.begin(), right.end(), minCmp);
    push_heap(left.begin(), left.end(), maxCmp);

    // each time one of the buckets start to grow
    // we need to balance them moving the front to another bucket
    if (abs((int)(left.size() - right.size())) > 1) {
        rebalanceHeaps(left, right);
    }

    if (left.size() == right.size()) {
        return (left.front() + right.front()) / 2;
    }

    return (left.size() > right.size()) ? left.front() : right.front();
}

int main() {
    float n;

    // left bucket represents max heap (maximum element is at the front)
    // right bucker represents min heap (min element is at the front)
    deque<float> leftBucket;
    deque<float> rightBucket;

    while (true) {
        cin >> n;
        cout << getRunningMedian(n, leftBucket, rightBucket) << endl;
    }
}
