#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string encodeInterval(char symbol, int count) {
    return to_string(count) + symbol;
}

string decodeInterval(char symbol, int count) {
    string result;

    for (int i = 0; i < count; i++) {
        result += symbol;
    }

    return result;
}

string encode(const string & s) {
    char prev = s[0];
    int curr = 1;
    string result;

    for (auto it = next(s.begin()); it != s.end(); ++it) {
        if (prev == *it) {
            curr++;
        } else {
            result += encodeInterval(prev, curr);
            prev = *it;
            curr = 1;
        }
    }

    result += encodeInterval(prev, curr);

    return result;
}

string decode(const string & s) {
    string result;

    for (auto it = s.begin(); it != s.end(); it += 2) {
        int count = *it - '0';
        char symbol = *next(it);

        result += decodeInterval(symbol, count);
    }

    return result;
}

void Test() {
    {
        string s = "AAAABBCCDAA";
        assert(decode(encode(s)) == s);
    }
    {
        string s = "A";
        assert(decode(encode(s)) == s);
    }
    {
        string s = "AB";
        assert(decode(encode(s)) == s);
    }
}

int main() {
    Test();

    string s;
    cin >> s;

    cout << decode(encode(s)) << endl;
}
