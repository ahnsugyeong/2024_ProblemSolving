/*
 ✅ baekjoon 8958
 문제 유형: 재귀?

 if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

 if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

 if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

 otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

 */

#include <bits/stdc++.h>

using namespace std;


int dp[21][21][21];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if (dp[a][b][c]) return dp[a][b][c];
    if (a < b && b < c) return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    int a, b, c;

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }


    return 0;
}