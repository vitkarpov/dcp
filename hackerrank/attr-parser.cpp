#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <cassert>

using namespace std;

vector<string> read(int n) {
  vector<string> r;
  for (int k = 0; k < n; k++) {
    string s;
    getline(cin, s);
    r.push_back(s);
  }
  return r;
}

int main() {
  int n, m;
  cin >> n >> m;

  stack<string> st;
  unordered_map<string, string> attrs;

  string tmp;
  getline(cin, tmp);

  for (const string& s : read(n)) {
    assert(s[0] == '<');

    if (s[0] == '<' && s[1] == '/') {
      st.pop();
    } else {
      int i = 1;
      while (s[i] != ' ' && s[i] != '>') {
        i++;
      }
      string name = s.substr(1, i - 1);

      if (!st.empty()) {
        st.push(st.top() + '.' + name);
      } else {
        st.push(name);
      }

      string key, value;
      while (i < s.size()) {
        if (s[i] == ' ' || s[i] == '>') {
          attrs[st.top() + '~' + key] = value;
        } else {
          int j = i;
          while (s[i] != ' ') {
            i++;
          }
          key = s.substr(j, i - j);
          assert(s[i++] == ' ');
          assert(s[i++] == '=');
          assert(s[i++] == ' ');
          assert(s[i++] == '"');
          j = i;
          while (s[i] != '"') i++;
          value = s.substr(j, i - j);
        }
        i++;
      }
    }
  }
  assert(st.size() == 0);

  for (const string& s : read(m)) {
    if (attrs.find(s) != attrs.end()) {
      cout << attrs[s] << endl;
    } else {
      cout << "Not Found!" << endl;
    }
  }

  return 0;
}
