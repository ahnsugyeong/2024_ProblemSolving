/*
 ✅ baekjoon 17837
 문제 유형: 구현, 시뮬레이션

 종료 조건) 턴이 진행되던 중에 말이 4개 이상 쌓이는 순간
 이동하려는 칸)
 1. 흰색: 그 칸으로 이동
 2. 빨간색: 이동 후 말 순서 반대로
 3. 파란색 == 벽
 */

#include <bits/stdc++.h>

using namespace std;


int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};

struct Piece {
    int i;
    int j;
    int dir;    // 0: 동, 1: 서, 2: 북, 3: 남
};
int N, K;
int chess[13][13];  // 0: 흰색, 1: 빨간색, 2: 파란색
vector<int> pieces[13][13];
vector<Piece> pieceInfo;

int getReverseDir(int dir) {
    if (dir == 0) return 1;
    if (dir == 1) return 0;
    if (dir == 2) return 3;
    if (dir == 3) return 2;
    return 2;
}

bool movePieces() {
    for (int idx = 0; idx < K; idx++) {
        Piece curPiece = pieceInfo[idx];

        int cur_i = curPiece.i;
        int cur_j = curPiece.j;
        int cur_dir = curPiece.dir;

        int new_i = cur_i + di[cur_dir];
        int new_j = cur_j + dj[cur_dir];

        if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1 || chess[new_i][new_j] == 2) {
            int new_dir = getReverseDir(cur_dir);
            pieceInfo[idx].dir = new_dir;
            new_i = cur_i + di[new_dir];
            new_j = cur_j + dj[new_dir];
            if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1 || chess[new_i][new_j] == 2) continue;
        }

        if (chess[new_i][new_j] == 0) {
            int k = find(pieces[cur_i][cur_j].begin(), pieces[cur_i][cur_j].end(), idx) - pieces[cur_i][cur_j].begin();
            int cur_size = pieces[cur_i][cur_j].size();

            for (int i = k; i < cur_size; i++) {
                int idxToMove = pieces[cur_i][cur_j][i];
                pieceInfo[idxToMove].i = new_i;
                pieceInfo[idxToMove].j = new_j;
                pieces[new_i][new_j].push_back(idxToMove);
            }

            for (int i = k; i < cur_size; i++) {
                pieces[cur_i][cur_j].pop_back();
            }
        }

        // 빨간색
        if (chess[new_i][new_j] == 1) {
            int k = find(pieces[cur_i][cur_j].begin(), pieces[cur_i][cur_j].end(), idx) - pieces[cur_i][cur_j].begin();
            int cur_size = pieces[cur_i][cur_j].size();
            for (int i = cur_size - 1; i >= k; i--) {
                int idxToMove = pieces[cur_i][cur_j][i];
                pieceInfo[idxToMove].i = new_i;
                pieceInfo[idxToMove].j = new_j;
                pieces[new_i][new_j].push_back(idxToMove);
            }

            for (int i = k; i < cur_size; i++) {
                pieces[cur_i][cur_j].pop_back();
            }
        }

        if (pieces[new_i][new_j].size() >= 4) return true;
    }

    return false;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> chess[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int piece_i, piece_j, piece_dir;
        cin >> piece_i >> piece_j >> piece_dir;
        pieces[piece_i - 1][piece_j - 1].push_back({i});
        pieceInfo.push_back({piece_i - 1, piece_j - 1, piece_dir - 1});
    }

    for (int i = 0; i < 1000; i++) {
        if (movePieces()) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}