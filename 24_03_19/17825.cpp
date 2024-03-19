/*
 ✅ baekjoon 17825
 문제 유형: 구현, 브루트포스, 시뮬레이션, 백트레킹
 참고: https://haejun0317.tistory.com/163
 */

#include <bits/stdc++.h>

using namespace std;

int board[33];  // 다음에 이동할 칸 정보 (빨간색 루트)
int score[33];  // 윷놀이 판 점수
int turn[35];   // 변환점 위치
int arr[10];    // 입력 받은 주사위
int piece[4];   // 말의 위치
bool visited[35];
int ans = 0;

void dfs(int cnt, int sum) {
    if (cnt == 10) {
        if (sum > ans) {
            ans = sum;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int cur = piece[i];
        int next = cur;

        int moveCnt = arr[cnt];  // 말이 움직일 칸 수

        // 현재 위치가 파란색 칸이라면
        if (turn[next] > 0) {
            next = turn[next];  // 다음 위치로 이동
            moveCnt--;
        }

        while (moveCnt--) {
            next = board[next];
        }

        if (next != 21 && visited[next] == true) continue;

        visited[cur] = false;
        visited[next] = true;
        piece[i] = next;

        dfs(cnt + 1, sum + score[next]);

        visited[cur] = true;
        visited[next] = false;
        piece[i] = cur;

    }
}


int main() {
    // initialize score
    for (int i = 1; i < 21; i++) {
        score[i] = i * 2;
    }
    score[22] = 13;
    score[23] = 16;
    score[24] = 19;
    score[25] = 25;
    score[26] = 30;
    score[27] = 35;
    score[28] = 28;
    score[29] = 27;
    score[30] = 26;
    score[31] = 22;
    score[32] = 24;

    // 다음 이동 위치 기록
    for (int i = 0; i < 32; i++) {
        board[i] = i + 1;
    }
    board[21] = 21; // 도착
    board[27] = 20;
    board[30] = 25;
    board[32] = 25;


    // 변환점 정보
    turn[5] = 22;
    turn[10] = 31;
    turn[15] = 28;


    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    dfs(0, 0);

    cout << ans << '\n';

}