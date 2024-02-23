/*
 ✅ baekjoon 1012
 문제 유형: BFS
 */

#include <bits/stdc++.h>

using namespace std;

int T;
int M, N, K;
int cabbageMap[51][51];
bool visited[51][51];
int dX[4] = {1, -1, 0, 0};
int dY[4] = {0, 0, 1, -1};

void BFS(pair<int, int> cabbage) {
    queue<pair<int, int>> Q;
    Q.push(cabbage);
    visited[cabbage.first][cabbage.second] = true;
    cabbageMap[cabbage.first][cabbage.second] = 0;

    while (!Q.empty()) {
        int cur_X = Q.front().first;
        int cur_Y = Q.front().second;
        Q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int new_X = cur_X + dX[idx];
            int new_Y = cur_Y + dY[idx];
            if (new_X < 0 || new_X > M - 1 || new_Y < 0 || new_Y > N - 1) continue;
            if (visited[new_X][new_Y] || cabbageMap[new_X][new_Y] == 0) continue;
            visited[new_X][new_Y] = true;
            cabbageMap[new_X][new_Y] = 0;
            Q.push({new_X, new_Y});
        }
    }
}

int getWormCount() {
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (cabbageMap[i][j]) {
                fill(&visited[0][0], &visited[51][0], false);
                BFS({i, j});
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        fill(&cabbageMap[0][0], &cabbageMap[51][0], 0);
        for (int j = 0; j < K; j++) {
            int X, Y;
            cin >> X >> Y;
            cabbageMap[X][Y] = 1;
        }
        cout << getWormCount() << '\n';
    }
}