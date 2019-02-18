#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void dump(vector<string> v) {
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
}

pair<vector<string>, bool> get_sentence(set<string> dict, string s) {
    if (s.size() == 0) {
        return {{}, true};
    }

    for (int i = 0; i < s.size(); i++) {
        string start = s.substr(0, i + 1);
        string end = s.substr(i + 1);

        if (dict.find(start) != dict.end()) {
            auto next = get_sentence(dict, end);

            if (next.second) {
                vector<string> result = {start};
                copy(next.first.begin(), next.first.end(), back_inserter(result));

                return {result, true};
            }
        }
    }

    return {{}, false};
}

int main() {
    int n;
    cin >> n;

    set<string> dict;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dict.insert(s);
    }

    string s;
    cin >> s;

    auto result = get_sentence(dict, s);

    if (result.second) {
        dump(result.first);
    } else {
        cout << "null" << endl;
    }
}
