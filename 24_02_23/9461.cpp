/*
 ✅ baekjoon 9461
 문제 유형: DP
 P(1): 1
 P(2): 1
 P(3): 1
 P(4): 2
 P(5): 2
 P(6): 3
 P(7): 4
 P(8): 5
 P(9): 7
 P(10): 9
 P(11): 12
 P(12): 16

 점화식: dp[i] = dp[i - 2] + dp[i - 3]
 */

#include <bits/stdc++.h>

using namespace std;

int T;
long long dp[101];

int main() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= 100; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}