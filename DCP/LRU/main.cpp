#include <iostream>
#include <unordered_map>
#include <list>
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

    void set(int key, int value) {
        if (storage.find(key) != storage.end()) {
            queue.erase(storage[key]);
            queue.push_front(*storage[key]);
            queue.front()->value = value;
        } else {
            Node * node = new Node(key, value);
            queue.push_front(node);
            storage[key] = queue.begin();
        }
        if (queue.size() > capacity) {
            storage.erase(queue.back()->key);
            queue.pop_back();
        }
    }

    int get(int key) {
        if (storage.find(key) == storage.end()) {
            return -1;
        }

        queue.erase(storage[key]);
        queue.push_front(*storage[key]);

        return queue.front()->value;
    }
private:
    int capacity;
    list<Node *> queue;
    unordered_map<int, decltype(queue.begin())> storage;
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
