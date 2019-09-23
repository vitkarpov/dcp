class Solution {
 public:
  string reverseVowels(string s) {
    unordered_set<char> vowels = {'a', 'A', 'e', 'E', 'i',
                                  'I', 'o', 'O', 'u', 'U'};
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      if (find(vowels.begin(), vowels.end(), s[left]) == vowels.end()) {
        left++;
      } else if (find(vowels.begin(), vowels.end(), s[right]) == vowels.end()) {
        right--;
      } else {
        swap(s[left++], s[right--]);
      }
    }
    return s;
  }
};
