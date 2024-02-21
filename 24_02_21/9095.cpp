/*
 ✅ baekjoon 9095
 문제 유형: DP

 dp[i]는
 dp[i - 1]에 1을 더한 경우,
 dp[i - 2]에 2를 더한 경우,
 dp[i - 3]에 3을 더한 경우의 합으로 이루어지게 된다.
 따라서, 점화식은 dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]가 된다.
 */

#include <bits/stdc++.h>

using namespace std;

int T;
int dp[11];

int main() {
    cin >> T;

    dp[1] = 1;  // 1
    dp[2] = 2;  // 1 + 1, 2
    dp[3] = 4;  // 1 + 1 + 1, 1 + 2, 2 + 1, 3

    for (int i = 4; i <= 10; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    while (T--) {
        int index;
        cin >> index;
        cout << dp[index] << '\n';
    }

    return 0;
}
