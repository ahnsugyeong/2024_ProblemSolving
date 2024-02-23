/*
 ✅ baekjoon 10844
 문제 유형: DP

 1 2 3 4 5 6 7 8 9
 dp[1][0] = 0
 dp[1][1] = 1
 dp[1][2] = 1
 dp[1][3] = 1
 dp[1][4] = 1
 dp[1][5] = 1
 dp[1][6] = 1
 dp[1][7] = 1
 dp[1][8] = 1
 dp[1][9] = 1

 10 12 21 23 32 34 43 44 54 56 65 67 76 78 87 89 98
 dp[1][0] = 1 (dp[0][1])
 dp[1][1] = 1 (dp[0][0] + dp[0][2])
 dp[1][2] = 1 (dp[0][1] + dp[0][3])
 .
 .

 */

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[101][10];

int main() {
    cin >> N;

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][1];
            else if (j == 9) dp[i][j] = dp[i - 1][8];
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            dp[i][j] %= 1000000000;
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[N][i];
        ans %= 1000000000;
    }
    cout << ans << '\n';
}
