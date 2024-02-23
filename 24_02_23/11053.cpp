/*
 ✅ baekjoon 11053
 문제 유형: DP
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int A[1001];
int dp[1001];

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        int maxDp = 0;
        for (int j = 1; j < i; j++) {
            if (A[i] > A[j] && dp[j] > maxDp) maxDp = dp[j];
        }
        dp[i] = maxDp + 1;
    }

    int ans = INT_MIN;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}