#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

bool isBalanced(string s) {
    vector<char> open = {'(', '{', '['};
    map<char, char> closed = {{')', '('}, {'}', '{'}, {']', '['}};

    stack<char> brackets;

    for (auto it = s.begin(); it != s.end(); ++it) {
        char curr = *it;

        if (find(open.begin(), open.end(), curr) != open.end()) {
            brackets.push(curr);
        } else {
            auto it = closed.find(curr);

            if (it != closed.end()) {
                if (brackets.top() != it->second) {
                    return false;
                }
                brackets.pop();
            }
        }
    }

    return brackets.size() == 0;
}

void Test() {
    assert(isBalanced("([])[]({})"));
    assert(!isBalanced("([)]"));
    assert(!isBalanced("((()"));
}

int main() {
    Test();

    string s;
    cin >> s;

    cout << isBalanced(s) << endl;
}
