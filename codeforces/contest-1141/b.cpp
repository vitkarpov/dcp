#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int first_streak = 0;
  int last_streak = 0;
  int max_streak = 0;
  int curr_streak = 0;
  int prev = -1;
  bool first_streak_broken = false;

  for (int i = 0; i < n; i++) {
    int curr;
    cin >> curr;

    if (curr == 0) {
      first_streak_broken = true;
      max_streak = max(max_streak, curr_streak);
      curr_streak = 0;
    } else if (curr == 1) {
      if (!first_streak_broken) {
        first_streak++;
      }
      if (curr == prev) {
        curr_streak++;
      } else {
        curr_streak = 1;
      }
      if (i == n - 1) {
        last_streak = curr_streak;
      }
    }
    prev = curr;
  }
  int mid_streak =
      first_streak > 0 && last_streak > 0 ? first_streak + last_streak : 0;

  cout << max(mid_streak, max(max_streak, curr_streak)) << endl;
}
