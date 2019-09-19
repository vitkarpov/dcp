class Solution {
 private:
  int gcd(int a, int b) {
    if (a == 0) {
      return b;
    }
    return gcd(b % a, a);
  }

 public:
  string gcdOfStrings(const string& str1, const string& str2) {
    string s1 = str1.size() > str2.size() ? str1 : str2;
    string s2 = str1.size() > str2.size() ? str2 : str1;

    if (s1 + s2 == s2 + s1) {
      return str1.substr(0, gcd(s1.size(), s2.size()));
    }
    return "";
  }
};
