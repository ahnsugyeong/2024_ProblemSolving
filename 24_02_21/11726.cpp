/*
 ✅ baekjoon 11726
 문제 유형: DP
 2*n 크기의 직사각형을 1*2, 2*1 타일로 채우는 방법의 수

 dp[i]는
 dp[i - 1] 모양에 2*1 타일 1개를 붙이는 경우의 수,
 dp[i - 2] 모양에 1*2 타일 2개를 붙이는 경우의 수를 합친 경우로 이루어져 있다.
 따라서, 점화식은 dp[i] = dp[i - 1] + dp[i - 2]가 된다.
 */

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1001];

int main() {
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n];

    return 0;
}