/*
 ✅ baekjoon 6550
 문제 유형: 문자열
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        string s, t;
        cin >> s >> t;
        if (cin.eof()) break;
        int index = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[index]) {
                index++;
            }
        }
        if (index == s.size()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}