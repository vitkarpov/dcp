#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(const string& s, const string& p) {
    vector<int> result;
    vector<int> window(256, 0);
    int lenS = s.size();
    int lenP = p.size();

    for (int i = 0; i <= lenS; i++) {
      if (i >= lenP) {
        for (int j = 0; j < lenP; j++) {
          window[p[j]]--;
        }
        bool isAnagram = true;
        for (int j = 0; j < lenP; j++) {
          if (window[p[j]] != 0) {
            isAnagram = false;
            break;
          }
        }
        if (isAnagram) {
          result.push_back(i - lenP);
        }
        for (int j = 0; j < lenP; j++) {
          window[p[j]]++;
        }
        window[s[i - lenP]]--;
      }
      if (i < lenS) {
        window[s[i]]++;
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
