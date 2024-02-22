/*
 ✅ baekjoon 11057
 문제 유형: DP
 N = 1)
 0
 1
 2
 3
 4
 5
 6
 7
 8
 9
 -> 10

 N = 2)
 00 01 02 03 04 05 06 07 08 09
 11 12 13 14 15 16 17 18 19
 22 23 24 25 26 27 28 29
 33 34 35 36 37 38 39
 44 45 46 47 48 49
 55 56 57 58 59
 66 67 68 69
 77 78 79
 88 89
 99
 -> 55

 dp[][]의 의미?
 : a자리의 수에서 b가 가장 마지막에 왔을 때, 오르막수가 될 수 있는 경우의 수

 */

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1001][10];

int main() {
    cin >> N;
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += dp[N][i];
        ans %= 10007;
    }
    cout << ans << '\n';
}