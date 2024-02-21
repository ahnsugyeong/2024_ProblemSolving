/*
 ✅ baekjoon 1149
 문제 유형: DP

 - 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
 - N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
 - i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1001][3];
int rgb[3];

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> rgb[j];
            int minVal = INT_MAX;

            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                minVal = min(minVal, dp[i - 1][k]);
            }
            dp[i][j] = rgb[j] + minVal;
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
        ans = min(ans, dp[N][i]);
    }

    cout << ans << '\n';
    return 0;
}
