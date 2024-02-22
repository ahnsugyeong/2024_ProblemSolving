/*
 ✅ baekjoon 2293
 문제 유형: DP

 동전의 관점에서 생각하기!
 DP[Y] = DP[Y] + DP[Y - X]

 */

#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> prices;
int dp[10001];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.push_back(price);
    }

    dp[0] = 1;
    for (int i = 0; i < prices.size(); i++) {
        int price = prices[i];
        for (int j = price; j <= k; j++) {
            dp[j] += dp[j - price];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}