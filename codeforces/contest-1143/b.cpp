#include <bits/stdc++.h>

using namespace std;

int get_max(int n) {
  if (n % 10 == 0) {
    n -= 1;
  }
  if (n < 10) {
    return n;
  }
  int num_nines = (int)log10(n);
  int first_digit = n / (int)pow(10, num_nines);
  int next_n = n % (int)pow(10, num_nines);
  int mult_nines = (int)pow(9, num_nines);

  int val1 = get_max(next_n) * first_digit;
  int val2 = first_digit > 1 ? (first_digit - 1) * mult_nines : mult_nines;

  return max(val1, val2);
}

int get_max2(int n) {
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    int k = i;
    int curr = 1;
    while (k % 10 > 0) {
      curr *= k % 10;
      k /= 10;
    }
    ans = max(ans, curr);
  }

  return ans;
}

int main() {
  int n;
  cin >> n;

  // for (int i = 1; i < n; i++) {
  //   int a1 = get_max(i);
  //   int a2 = get_max2(i);

  //   if (a1 != a2) {
  //     cout << a1 << " != " << a2 << "; i = " << i << endl;
  //     break;
  //   }
  // }
  cout << get_max(n) << endl;
}
