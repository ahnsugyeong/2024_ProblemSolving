/*
 ✅ baekjoon 14584
 문제 유형: 문자열
 */

#include <bits/stdc++.h>

using namespace std;

string str;
int N;
vector<string> words;


int main() {
    cin >> str >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    for (int i = 0; i < 26; i++) {
        string tmp = "";
        for (int j = 0; j < str.size(); j++) {
            tmp += (str[j] - 'a' + i) % 26 + 'a';
        }
        for (int j = 0; j < words.size(); j++) {
            if (tmp.find(words[j]) != -1) {
                cout << tmp << '\n';
                return 0;
            }
        }
    }
    return 0;
}