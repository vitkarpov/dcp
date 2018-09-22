#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Node {
public:
    Node(char _value) : value(_value) {};
    char value;
    Node * left;
    Node * right;
};

void read(vector<Node *> & v, int n) {
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        v[i] = new Node(tmp);
    }
}

vector<Node *> slice(const vector<Node *> v, int start, int end) {
    return vector<Node *>(v.begin() + start, v.begin() + end);
}

int findNodePos(const vector<Node *> v, Node * needle) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        Node * node = *it;

        if (node->value == needle->value) {
            return it - v.begin();
        }
    }
    return -1;
}

Node * reconstruct(vector<Node *> preorder, vector<Node *> inorder) {
    if (preorder.size() == 0 && inorder.size() == 0) {
        return NULL;
    }
    if (preorder.size() == 1 && inorder.size() == 1) {
        return *preorder.begin();
    }

    Node * root = *preorder.begin();
    int rootPos = findNodePos(inorder, root);

    root->left = reconstruct(
        slice(preorder, 1, 1 + rootPos),
        slice(inorder, 0, rootPos)
    );
    root->right = reconstruct(
        slice(preorder, 1 + rootPos, preorder.size()),
        slice(inorder, 1 + rootPos, inorder.size())
    );

    return root;
}

int main() {
    int n;
    cin >> n;

    vector<Node *> preorder(n);
    read(preorder, n);

    vector<Node *> inorder(n);
    read(inorder, n);

    Node * root;
    root = reconstruct(preorder, inorder);
}
