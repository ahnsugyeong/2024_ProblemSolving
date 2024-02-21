/*
 ✅ baekjoon 1463
 문제 유형: DP

 1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
 2. X가 2로 나누어 떨어지면, 2로 나눈다.
 3. 1을 뺀다.
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1000001]; // index를 1로 만들기 위해 필요한 연산의 수

int main() {
    cin >> N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
    }

    cout << dp[N];

    return 0;
}