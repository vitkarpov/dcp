#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define ull unsigned long long int

struct Song {
  int time;
  int beauty;
  Song(int _t, int _b) : time(_t), beauty(_b){};
  bool operator<(const Song& rhs) const { return beauty > rhs.beauty; }
};

int main() {
  int n, k;
  cin >> n >> k;

  vector<Song> songs;
  for (int i = 0; i < n; i++) {
    int t, b;
    cin >> t >> b;
    songs.push_back({t, b});
  }

  sort(songs.begin(), songs.end());

  vector<ull> sums(n);
  sums[0] = (ull)songs[0].time;

  for (int i = 1; i < n; i++) {
    sums[i] = sums[i - 1] + (ull)songs[i].time;
  }

  ull ans = 0;
  ull prev_smallest_sum = 0;
  priority_queue<int, vector<int>, greater<int>> time_heap;

  for (int i = 0; i < n; i++) {
    time_heap.push(songs[i].time);
    if (i >= k) {
      prev_smallest_sum += (ull)time_heap.top();
      time_heap.pop();
    }
    ans = max(ans, (sums[i] - prev_smallest_sum) * songs[i].beauty);
  }
  cout << ans << endl;
}
