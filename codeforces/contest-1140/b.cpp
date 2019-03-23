#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int min;

    for (int j = 0; j < k; j++) {
      if (s[j] == '>' || s[k - 1 - j] == '<') {
        min = j;
        break;
      }
    }

    cout << min << endl;
  }
}
