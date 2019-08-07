#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(const string& s, const string& p) {
    vector<int> result;
    vector<int> window(26, 0);
    vector<int> ref(26, 0);
    int lenS = s.size();
    int lenP = p.size();

    if (lenP > lenS) {
      return {};
    }

    for (int i = 0; i < lenP; i++) {
      ref[p[i] - 'a']++;
      window[s[i] - 'a']++;
    }

    for (int i = 0; i <= lenS - lenP; i++) {
      if (window == ref) {
        result.push_back(i);
      }
      window[s[i] - 'a']--;
      if (i + lenP < lenS) {
        window[s[i + lenP] - 'a']++;
      }
    }
    return result;
  }
};

int main() {
  Solution s;

  {
    vector<int> v = {0, 6};
    assert(s.findAnagrams("cbaebabacd", "abc") == v);
  }
  {
    vector<int> v = {0, 1, 2};
    assert(s.findAnagrams("abab", "ab") == v);
  }
  {
    vector<int> v = {0, 3, 9, 11, 12};
    assert(s.findAnagrams("cbaacbebaabcbacd", "abc") == v);
  }
  {
    vector<int> v = {0};
    assert(s.findAnagrams("bac", "abc") == v);
  }
  {
    vector<int> v = {};
    assert(s.findAnagrams("aaaaaaaaaa", "aaaaaaaaaaaaa") == v);
  }

  return 0;
}
