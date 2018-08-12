#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;

class Node {
public:
    Node(int _val) : val(_val) {}; 
    int val = 0;
    Node * next = NULL;
};

string print(Node * root) {
    stringstream ss;
    Node * curr = root;

    while (curr != NULL) {
        ss << curr->val;
        curr = curr->next;
    }

    return ss.str();
}

Node * mkList(vector<int> values) {
    Node * root = new Node(values[0]);
    Node * prev = root;

    for (auto it = next(values.begin()); it != values.end(); ++it) {
        prev->next = new Node(*it);
        prev = prev->next;
    }

    return root;
}

Node * rmNode(Node * root, int k) {
    Node * p1 = root;
    Node * p2 = root;
    Node * prev = NULL;

    while (p2 != NULL) {
        k--;
        if (k < 0) {
            prev = p1;
            p1 = p1->next;
        }
        p2 = p2->next;
    }
    if (prev == NULL) {
        return root->next;
    }
    prev->next = p1->next;

    return root;
}

void Test() {
    {
        Node * root = mkList({1, 2, 3, 4, 5});
        assert(print(rmNode(root, 1)) == "1234");
    }
    {
        Node * root = mkList({1, 2, 3, 4, 5});
        assert(print(rmNode(root, 2)) == "1235");
    }
    {
        Node * root = mkList({1, 2, 3, 4, 5});
        assert(print(rmNode(root, 3)) == "1245");
    }
    {
        Node * root = mkList({1, 2, 3, 4, 5});
        assert(print(rmNode(root, 4)) == "1345");
    }
    {
        Node * root = mkList({1, 2, 3, 4, 5});
        assert(print(rmNode(root, 5)) == "2345");
    }
}

int main() {
    Test();

    int n;
    cin >> n;
    Node * root = mkList({1, 2, 3, 4, 5});

    cout << print(rmNode(root, n)) << endl;
}
