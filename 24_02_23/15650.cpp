/*
 ✅ baekjoon 15650
 문제 유형: 백트래킹
 "result[index - 1] > i" 조건 추가!
 */

#include <bits/stdc++.h>

using namespace std;

int N, M;
int result[8];
bool visited[8];

void combi(int index) {
    if (index == M) {
        for (int i = 0; i < M; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] || result[index - 1] > i) continue;
        visited[i] = true;
        result[index] = i;
        combi(index + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> N >> M;
    combi(0);
    return 0;
}