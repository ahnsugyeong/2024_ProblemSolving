/*
 ✅ baekjoon 9663
 문제 유형: 백트래킹
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int cnt = 0;
int chess[16];  // chess[1]에 3이라는 값이 들어있으면, 1행 3열에 퀸이 배치되어 있다는 뜻이다.

bool isValid(int index) {
    for (int i = 0; i < index; i++) {
        if (chess[i] == chess[index] || abs(chess[i] - chess[index]) == index - i) return false;
    }
    return true;
}

void placeQueen(int index) {
    if (index == N) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        chess[index] = i;
        if (isValid(index)) placeQueen(index + 1);  // 유효하다면 다음 행의 퀸 배치, 유효하지 않다면 반복문 돌면서 다른 위치에 배치.
    }
}

int main() {
    cin >> N;
    placeQueen(0);
    cout << cnt << '\n';
    return 0;
}