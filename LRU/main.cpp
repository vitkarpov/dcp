#include <iostream>
#include <unordered_map>
#include <deque>
#include <cassert>

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

    assert(cache.get(2) == 2);
    assert(cache.get(1) == -1);

    cache.set(1, 1);
    cache.set(1, 5);

    assert(cache.get(1) == 5);
    assert(cache.get(2) == 2);

    cache.set(8, 8);

    assert(cache.get(1) == -1);
    assert(cache.get(2) == 2);
    assert(cache.get(8) == 8);

}
