/*
 ✅ baekjoon 1904
 문제 유형: DP
 N = 1)
 1 -> 1개
 N = 2)
 00 11 -> 2개
 N = 3)
 111 001 110 -> 3개
 N = 4)
 0011 0000 1001 1100 1111 -> 5개
 N = 5)
 11111 00111 10011 11001 11100 00001 10000 00100 -> 8개

 피보나치 수열!
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1000001];

int main() {
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    cout << dp[N] << '\n';
}