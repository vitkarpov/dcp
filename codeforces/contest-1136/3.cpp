#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void read_matrix(vector<vector<int>> &m, int xx, int yy) {
  for (int i = 0; i < yy; i++) {
    for (int j = 0; j < xx; j++) {
      cin >> m[i][j];
    }
  }
}

bool check_transform(const vector<vector<int>> &m1,
                     const vector<vector<int>> &m2, int xx, int yy) {
  // first row
  for (int x = 0; x < xx; x++) {
    vector<int> tmp1;
    vector<int> tmp2;
    int i = x;
    int j = 0;

    while (i >= 0 && j < yy) {
      tmp1.push_back(m1[j][i]);
      tmp2.push_back(m2[j][i]);
      i--;
      j++;
    }
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());

    if (!equal(tmp1.begin(), tmp1.end(), tmp2.begin())) {
      return false;
    }
  }

  // last col
  for (int y = 1; y < yy; y++) {
    vector<int> tmp1;
    vector<int> tmp2;
    int i = xx - 1;
    int j = y;

    while (i >= 0 && j < yy) {
      tmp1.push_back(m1[j][i]);
      tmp2.push_back(m2[j][i]);
      i--;
      j++;
    }
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());

    if (!equal(tmp1.begin(), tmp1.end(), tmp2.begin())) {
      return false;
    }
  }

  return true;
}

int main() {
  int yy, xx;
  cin >> yy >> xx;

  vector<vector<int>> m1(yy, vector<int>(xx));
  vector<vector<int>> m2(yy, vector<int>(xx));

  read_matrix(m1, xx, yy);
  read_matrix(m2, xx, yy);

  if (check_transform(m1, m2, xx, yy)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
