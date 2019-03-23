#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<long, pair<long, long>>> songs;
  for (int i = 0; i < n; i++) {
    long t, b;
    cin >> t >> b;
    songs.push_back({-b, {t, 0}});
  }

  sort(songs.begin(), songs.end());

  long sum = 0;
  for (int i = 0; i < n; i++) {
    long b = songs[i].first;
    long t = songs[i].second.first;

    sum += t;
    songs[i] = {-b, {t, sum}};
  }
  long ans = 0;
  long sum_short = 0;
  vector<long> heap;
  for (int i = 0; i < n; i++) {
    heap.push_back(-songs[i].second.first);
    push_heap(heap.begin(), heap.end());
    if (i >= k) {
      pop_heap(heap.begin(), heap.end());
      sum_short -= heap.back();
      heap.pop_back();
    }
    long curr = (songs[i].second.second - sum_short) * songs[i].first;
    ans = max(ans, curr);
  }
  cout << ans << endl;
}
