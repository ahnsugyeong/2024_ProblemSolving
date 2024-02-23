/*
 ✅ baekjoon 15649
 문제 유형: 백트래킹
 */

#include <bits/stdc++.h>

using namespace std;

int N, M;

int result[8];
bool visited[8];

void combi(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        result[cnt] = i;
        combi(cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> N >> M;
    combi(0);
    return 0;
}