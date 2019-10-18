#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

typedef pair<int, int> Node;

class LRUCache {
  list<Node> q;
  unordered_map<int, list<Node>::iterator> m;
  int capacity;

  void remove(const list<Node>::iterator& n) {
    m.erase(n->first);
    q.erase(n);
  }
  void insert(int key, int value) {
    q.push_back(make_pair(key, value));
    m[key] = prev(q.end());
  }

 public:
  LRUCache(int v) : capacity(v) {}

  int get(int key) {
    if (m.find(key) == m.end()) {
      return -1;
    }
    int value = m[key]->second;
    remove(m[key]);
    insert(key, value);
    return value;
  }

  void put(int key, int value) {
    if (q.size() >= capacity) {
      remove(q.begin());
    }
    insert(key, value);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
  LRUCache* obj = new LRUCache(2);
  obj->put(1, 1);
  obj->put(2, 2);
  cout << obj->get(1) << endl;
  obj->put(3, 3);
  cout << obj->get(2) << endl;
  obj->put(4, 4);
  cout << obj->get(1) << endl;
  cout << obj->get(3) << endl;
  cout << obj->get(4) << endl;
}
