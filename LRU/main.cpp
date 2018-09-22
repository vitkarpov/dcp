#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;

class Node {
public:
    Node(int _key, int _value) : key(_key), value(_value) {};
    int key;
    int value;
};

class LRU {
public:
    LRU(int n) : capacity(n) {};

    void set(int key, int val) {
        if (storage.find(key) != storage.end()) {
            storage[key]->value = val;
        } else {
            storage[key] = new Node(key, val);
        }
        touch(key);
    }

    int get(int key) {
        if (storage.find(key) == storage.end()) {
            return -1;
        }

        int val = storage[key]->value;
        touch(key);

        return val;
    }
private:
    int capacity;
    deque<Node *> queue;
    unordered_map<int, Node *> storage;

    void touch(int key) {
        // move last recent used node to the front
        queue.push_front(storage[key]);

        // maintain the capacity by removing least recent used element
        if (storage.size() > capacity) {
            storage.erase(queue.back()->key);
            queue.pop_back();
        }
    }
};

int main() {
    LRU cache(2);

    cache.set(2, 2);

    // 2, it's what we've just set for key=2
    cout << cache.get(2) << endl;
    // -1, there's no such node yet
    cout << cache.get(1) << endl;

    cache.set(1, 1);
    cache.set(1, 5);

    // 5, it's last element has been set for key=1
    cout << cache.get(1) << endl;
    // 2, nothing's changed for key=2
    cout << cache.get(2) << endl;

    cache.set(8, 8);

    // -1, key=2 is no longer available because of it was least recent used
    cout << cache.get(2) << endl;
    // 8, as expected
    cout << cache.get(8) << endl;

}
