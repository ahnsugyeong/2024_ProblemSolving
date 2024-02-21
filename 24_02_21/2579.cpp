/*
 ✅ baekjoon 2579
 문제 유형: DP

 1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
 2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
 3. 마지막 도착 계단은 반드시 밟아야 한다.

 dp[1] = 10
 dp[2] = 20
 dp[3] = 10 + 15 vs
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int stairs[301];
int dp[301];    // index 번째 계단까지 얻을 수 있는 총 점수의 최댓값

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> stairs[i];
    }

    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    for (int i = 3; i <= N; i++) {
        dp[i] = stairs[i] + max(dp[i - 2], dp[i - 3] + stairs[i - 1]);
    }

    cout << dp[N];

    return 0;
}