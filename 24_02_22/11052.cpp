/*
 ✅ baekjoon 11052
 문제 유형: DP
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int P[1001];
int dp[1001];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = P[i];
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], P[j] + dp[i - j]);
        }
    }
    cout << dp[N];
}