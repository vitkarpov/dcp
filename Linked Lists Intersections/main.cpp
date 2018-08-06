#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

class Node {
public:
    Node(int _value) : value(_value) {};
    int value;
    Node * next = NULL;
};

void print(Node * root) {
    while (root != NULL) {
        cout << root->value << " ";
        root = root->next;
    }
}

Node * readFromStdin(int n) {
    int val;
    cin >> val;

    Node * root = new Node(val);
    Node * prev = root;

    for (int i = 0; i < n - 1; i++) {
        cin >> val;
        prev->next = new Node(val);
        prev = prev->next;
    }

    return root;
}

Node * getIntersectionNode(Node * bigger, Node * smaller, int diff) {
    Node * p1 = bigger;
    Node * p2 = smaller;

    while (diff > 0) {
        p1 = p1->next;
        diff--;
    }

    Node * intersection = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->value == p2->value) {
            if (intersection == NULL) {
                intersection = p1;
            }
        } else {
            intersection = NULL;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return intersection;
}

Node * getIntersectionNode(Node * l1, Node * l2, int n, int m) {
    Node * p1 = l1;
    Node * p2 = l2;

    if (n > m) {
        return getIntersectionNode(l1, l2, n - m);
    }
    return getIntersectionNode(l2, l1, m - n);
}

void Test() {
    Node * l1 = new Node(3);
    l1->next = new Node(8);
    l1->next->next = new Node(10);
    l1->next->next->next = new Node(8);
    l1->next->next->next->next = new Node(10);

    Node * l2 = new Node(99);
    l2->next = new Node(10);
    l2->next->next = new Node(8);
    l2->next->next->next = new Node(10);

    assert(getIntersectionNode(l1, l2, 5, 4)->value == 10);
}

int main() {
    Test();

    int n;
    cin >> n;

    Node * l1 = readFromStdin(n);

    int m;
    cin >> m;

    Node * l2 = readFromStdin(m);

    Node * intersection = getIntersectionNode(l1, l2, n, m);

    if (intersection != NULL) {
        cout << intersection->value << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
}
