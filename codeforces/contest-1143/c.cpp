#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  int parent;
  int pos;
  vector<Node*> children;
  Node(int _value, int _pos, int _parent)
      : value(_value), pos(_pos), parent(_parent){};
  bool operator<(const Node& rhs) const { return pos > rhs.pos; }
};

int main() {
  int n;
  cin >> n;

  vector<Node*> leaves;
  for (int i = 0; i < n; i++) {
    int parent, value;
    cin >> parent >> value;
    leaves.push_back(new Node(value, i + 1, parent - 1));
  }

  Node* root = NULL;

  for (auto node : leaves) {
    if (node->parent != -2) {
      Node* parent = leaves[node->parent];
      parent->children.push_back(node);
    } else {
      root = node;
    }
  }

  deque<Node*> q;
  q.push_back(root);

  vector<Node*> dropNodes;

  while (q.size() > 0) {
    Node* parent = q.front();
    q.pop_front();
    if (parent->value == 1) {
      bool drop = true;
      for (auto node : parent->children) {
        if (node->value == 0) {
          drop = false;
        }
      }
      if (drop == true) {
        dropNodes.push_back(parent);
      }
    }
    for (auto node : parent->children) {
      q.push_back(node);
    }
  }

  if (dropNodes.size() == 0) {
    cout << -1;
  } else {
    sort(dropNodes.begin(), dropNodes.end());
    for (int i = 0; i < dropNodes.size(); i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << dropNodes[i]->pos;
    }
  }
  cout << endl;
}
