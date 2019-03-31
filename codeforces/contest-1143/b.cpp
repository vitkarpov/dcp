#include <bits/stdc++.h>

using namespace std;

int get_max(int n) {
  if (n % 10 == 0) n -= 1;
  if (n < 10) return n;

  int num_nines = (int)log10(n);
  int first_digit = n / (int)pow(10, num_nines);

  int val1 = get_max(n % (int)pow(10, num_nines)) * first_digit;
  int val2 = max(1, first_digit - 1) * (int)pow(9, num_nines);

  return max(val1, val2);
}

int main() {
  int n;
  cin >> n;
  cout << get_max(n) << endl;
}
