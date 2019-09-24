class Solution {
 private:
  int getNext(int n) {
    int next = 0;

    while (n > 0) {
      int rem = n % 10;
      next += (rem * rem);
      n /= 10;
    }
    return next;
  }

 public:
  bool isHappy(int n) {
    int counter = 0;
    int next = getNext(n);
    unordered_set<int> used;

    while (next != 1) {
      counter++;
      next = getNext(next);

      if (find(used.begin(), used.end(), next) != used.end()) {
        return false;
      }
      used.insert(next);
    }
    return true;
  }
};
