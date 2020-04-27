#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(const string& s) {
  for (auto c : s) {
    if (c != s[0]) {
      return false;
    }
  }
  return true;
}

int shift(string& s, int pos) {
  int shift;

  if (s[pos] == 'W' && s[pos - 1] == 'B') {
    s[pos] = 'B';
    s[pos - 1] = 'W';
    shift = 1;
  } else if (s[pos] == 'B' && s[pos - 1] == 'W') {
    s[pos] = 'W';
    s[pos - 1] = 'B';
    shift = 1;
  } else if (s[pos] == 'W' && s[pos - 1] == 'W') {
    s[pos] = 'B';
    s[pos - 1] = 'B';
    shift = 2;
  } else if (s[pos] == 'B' && s[pos - 1] == 'B') {
    s[pos] = 'W';
    s[pos - 1] = 'W';
    shift = 2;
  }
  return shift;
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  for (int i = 1; i < s.size(); i++) {
    int k = 0;
    int pos = i;
    string copy = s;
    vector<int> moves;
    while (true) {
      if (check(copy)) {
        cout << k << endl;
        for (auto v : moves) {
          cout << v << ' ';
        }
        cout << endl;
        return 0;
      }
      if (pos >= s.size()) {
        break;
      }
      moves.push_back(pos - 1);
      pos += shift(copy, pos);
    }
  }
  cout << -1 << endl;
}
