/*
 ✅ baekjoon 13305
 문제 유형: Greedy
 */

#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> road(N - 1);
    vector<int> price(N);

    for (int i = 0; i < N - 1; i++) {
        cin >> road[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }

    long long minPrice = price[0];
    long long totalCost = 0;
    for (int i = 0; i < N - 1; i++) {
        if (price[i] < minPrice) {
            minPrice = price[i];
        }
        totalCost += (road[i] * minPrice);
    }

    cout << totalCost << '\n';

    return 0;
}