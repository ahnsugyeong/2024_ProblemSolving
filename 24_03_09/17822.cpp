/*
 ✅ baekjoon 17822
 문제 유형: 구현, 시뮬레이션

 1. 번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
 2. 원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
    - 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
    - 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, T;

void turnDisc(vector<vector<int>> &disc, int x, int d, int k) {
    for (int i = 0; i < N; i++) {
        if ((i + 1) % x != 0) continue;
        if (d == 0) {   // 시계 방향
            for (int cnt = 0; cnt < k; cnt++) {
                int tmp = disc[i][M - 1];
                for (int j = M - 1; j > 0; j--) {
                    disc[i][j] = disc[i][j - 1];
                }
                disc[i][0] = tmp;
            }

        } else if (d == 1) {    // 반시계 방향
            for (int cnt = 0; cnt < k; cnt++) {
                int tmp = disc[i][0];
                for (int j = 0; j < M - 1; j++) {
                    disc[i][j] = disc[i][j + 1];
                }
                disc[i][M - 1] = tmp;
            }
        }
    }
}

void removeDup(vector<vector<int>> &disc) {
    bool found = false;
    vector<vector<bool>> toRemove(N, vector<bool>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vector<pair < int, int>>
            adj;
            adj.push_back({i, (j - 1 + M) % M});    // left
            adj.push_back({i, (j + 1) % M});   // right
            if (i > 0) adj.push_back({i - 1, j});    // up
            if (i < N - 1)adj.push_back({i + 1, j});    // down
            for (auto &[ni, nj]: adj) {
                if ((disc[ni][nj] != 0) && (disc[i][j] == disc[ni][nj])) {
                    toRemove[ni][nj] = true;
                    toRemove[i][j] = true;
                    found = true;
                }
            }
        }
    }

    if (found) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (toRemove[i][j]) {
                    disc[i][j] = 0;
                }
            }
        }
    } else {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (disc[i][j] > 0) {
                    sum += disc[i][j];
                    cnt++;
                }
            }
        }

        double avg = (double) sum / (double) cnt;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (disc[i][j] == 0) continue;
                if (avg < disc[i][j]) disc[i][j]--;
                else if (avg > disc[i][j]) disc[i][j]++;
            }
        }
    }
}


int main() {
    cin >> N >> M >> T;

    vector<vector<int>> disc(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> disc[i][j];
        }
    }

    for (int i = 0; i < T; i++) {
        int x, d, k;
        cin >> x >> d >> k;
        turnDisc(disc, x, d, k);
        removeDup(disc);
    }


    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += disc[i][j];
        }
    }
    cout << sum << '\n';

    return 0;
}
