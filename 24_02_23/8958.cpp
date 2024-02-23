/*
 ✅ baekjoon 8958
 문제 유형: 구현, 문자열
 */

#include <bits/stdc++.h>

using namespace std;

int T;

int getScore(string str) {
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'O') {
            cnt++;
        } else {
            cnt = 0;
        }
        ans += cnt;
    }
    return ans;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;
        cout << getScore(str) << '\n';
    }
}