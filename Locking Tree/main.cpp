#include <iostream>
#include <cassert>

using namespace std;

class Node {
public:
    Node(int _val, Node * _left, Node * _right) : val(_val), left(_left), right(_right) {
        if (left != NULL) {
            left->parent = this;
        }
        if (right != NULL) {
            right->parent = this;
        }
    };

    int val;
    bool isLocked = false;

    Node * left = NULL;
    Node * right = NULL;
    Node * parent = NULL;

    bool lock() {
        return lockHelper(true);
    }

    bool unlock() {
        return lockHelper(false);
    }

private:
    int countOfLockedChildren = 0;

    bool lockHelper(bool lock) {
        if (lock && isLocked) {
            return false;
        }

        if (countOfLockedChildren > 0) {
            return false;
        }

        Node * curr = parent;

        while (curr != NULL) {
            if (curr->isLocked) {
                return false;
            }
            curr = curr->parent;
        }

        isLocked = lock;

        curr = parent;

        while (curr != NULL) {
            curr->countOfLockedChildren += lock ? 1 : -1;
            curr = curr->parent;
        }

        return true;
    }
};

int main() {
    Node * root = new Node(
        0,
        new Node(
            1,
            new Node(2, NULL, NULL),
            new Node(3, NULL, NULL)
        ),
        new Node(
            4,
            new Node(5, NULL, NULL),
            new Node(6, NULL, NULL)
        )
    );

    cout << "root->isLocked => false: ";
    assert(!root->isLocked);
    cout << "OK" << endl;

    cout << "root->left->lock() => true: ";
    assert(root->left->lock());
    cout << "OK" << endl;

    cout << "root->left->left->lock() => false: ";
    assert(!root->left->left->lock());
    cout << "OK" << endl;

    cout << "root->left->right->lock() => false: ";
    assert(!root->left->right->lock());
    cout << "OK" << endl;

    cout << "root->left->unlock() => true: ";
    assert(root->left->unlock());
    cout << "OK" << endl;

    cout << "root->left->left->lock() => true: ";
    assert(root->left->left->lock());
    cout << "OK" << endl;
}
