/*
 ✅ baekjoon 1525
 문제 유형: BFS
 */

#include <bits/stdc++.h>

using namespace std;

string str;
set<string> S;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int BFS() {
    queue<pair<string, int>> Q;
    Q.push({str, 0});   // first: 퍼즐의 상태, second: 이동 횟수
    S.insert(str);

    while (!Q.empty()) {
        string curStr = Q.front().first;
        int curCnt = Q.front().second;
        Q.pop();
        if (curStr == "123456780") return curCnt;

        int zeroIndex = curStr.find("0");
        int cur_i = zeroIndex / 3;
        int cur_j = zeroIndex % 3;

        for (int idx = 0; idx < 4; idx++) {
            int new_i = cur_i + di[idx];
            int new_j = cur_j + dj[idx];
            if (new_i < 0 || new_i > 2 || new_j < 0 || new_j > 2) continue;

            string newStr = curStr;
            int strIndex = new_i * 3 + new_j;
            swap(newStr[zeroIndex], newStr[strIndex]);

            if (S.find(newStr) != S.end()) continue;
            S.insert(newStr);
            Q.push({newStr, curCnt + 1});
        }
    }
    return -1;
}

int main() {
    str = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c;
            cin >> c;
            str += c;
        }
    }

    cout << BFS();

    return 0;
}