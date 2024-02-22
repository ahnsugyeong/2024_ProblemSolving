/*
 ✅ baekjoon 1697
 문제 유형: BFS
 */

#include <bits/stdc++.h>

using namespace std;

int N, K;
bool visited[100001];

int BFS() {
    queue<pair<int, int>> Q;    // first: 위치, second: 시간
    Q.push({N, 0});
    visited[N] = true;
    while (!Q.empty()) {
        int cur = Q.front().first;
        int time = Q.front().second;
        Q.pop();

        if (cur == K) return time;

        if (cur - 1 >= 0 && !visited[cur - 1]) {
            Q.push({cur - 1, time + 1});
            visited[cur - 1] = true;
        }

        if (cur + 1 <= 100000 && !visited[cur + 1]) {
            Q.push({cur + 1, time + 1});
            visited[cur + 1] = true;
        }

        if (cur * 2 <= 100000 && !visited[cur * 2]) {
            Q.push({cur * 2, time + 1});
            visited[cur * 2] = true;
        }
    }
}

int main() {
    cin >> N >> K;
    cout << BFS() << '\n';
    return 0;
}