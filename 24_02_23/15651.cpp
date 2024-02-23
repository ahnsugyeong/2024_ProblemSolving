/*
 ✅ baekjoon 15651
 문제 유형: 백트래킹
 */

#include <bits/stdc++.h>

using namespace std;

int N, M;
int result[8];


void combi(int index) {
    if (index == M) {
        for (int i = 0; i < M; i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        result[index] = i;
        combi(index + 1);
    }
}

int main() {
    cin >> N >> M;
    combi(0);
    return 0;
}