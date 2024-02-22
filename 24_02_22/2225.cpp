/*
 ✅ baekjoon 2225
 문제 유형: DP
 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수
 */

#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[201][201];   // N, K

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        dp[i][1] = 1;
    }

    for (int i = 1; i <= K; i++) {
        dp[1][i] = i;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= 1000000000;
        }
    }
    cout << dp[N][K] << '\n';
}