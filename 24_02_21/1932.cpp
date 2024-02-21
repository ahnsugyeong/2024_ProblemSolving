/*
 ✅ baekjoon 1932
 문제 유형: DP
 */

#include <bits/stdc++.h>

using namespace std;

int n;
int triangle[501][501];
int dp[501][501];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
            if (j == 0) {
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            } else {
                dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
            }

        }
    }

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;

    return 0;
}