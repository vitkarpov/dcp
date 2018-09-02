#include <iostream>

using namespace std;

class Node {
public:
    Node(Node * _left, Node * _right, int _val) : left(_left), right(_right), val(_val) {};
    Node * left;
    Node * right;
    int val;
};

void getSecondLargestNode(Node * root, int & count, Node *& ans) {
    if (root == NULL || count >= 2) {
        return;
    } 

    getSecondLargestNode(root->right, count, ans);
    count++;

    if (count == 2) {
        ans = root;
    } else {
        getSecondLargestNode(root->left, count, ans);
    }
};

Node * getSecondLargestNode(Node * root) {
    int count = 0;
    Node * ans = NULL;

    getSecondLargestNode(root, count, ans);

    return ans;
};

int main() {
    //    5
    //  /   \
    //  3    7
    // /\    /\
    // 2 4   6 8
    Node * root = new Node(
        new Node(
            new Node(NULL, NULL, 2),
            new Node(NULL, NULL, 4),
            3
        ),
        new Node(
            new Node(NULL, NULL, 6),
            new Node(NULL, NULL, 8),
            7
        ),
        5
    );

    // 7
    Node * ans = getSecondLargestNode(root);

    if (ans) {
        cout << ans->val << endl;
    } else {
        cout << "not found." << endl;
    }
}
