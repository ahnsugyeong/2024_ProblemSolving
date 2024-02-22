/*
 ✅ baekjoon 2667
 문제 유형: BFS
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int board[26][26];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
vector<pair<int, int>> house;
bool visited[26][26];
vector<int> ans;

int BFS(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push({i, j});
    visited[i][j] = true;

    int size = 0;
    while (!Q.empty()) {
        int cur_i = Q.front().first;
        int cur_j = Q.front().second;
        Q.pop();
        size++;
        for (int idx = 0; idx < 4; idx++) {
            int new_i = cur_i + di[idx];
            int new_j = cur_j + dj[idx];
            if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1) continue;
            if (board[new_i][new_j] == 0 || visited[new_i][new_j]) continue;
            visited[new_i][new_j] = true;
            Q.push({new_i, new_j});
        }
    }
    return size;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++) {
            board[i][j] = stoi(tmp.substr(j, 1));
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                ans.push_back(BFS(i, j));
            }
        }
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}