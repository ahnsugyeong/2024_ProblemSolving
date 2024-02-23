/*
 ✅ baekjoon 1309
 문제 유형: DP
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[100001][3];  // 0: XX, 1: XO, 2: OX

int main() {
    cin >> N;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
        for (int j = 0; j < 3; j++) {
            dp[i][j] %= 9901;
        }
    }
    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901 << '\n';
    return 0;
}