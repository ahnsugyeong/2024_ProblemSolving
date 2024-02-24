/*
 ✅ baekjoon 1920
 문제 유형: 정렬, 이분 탐색
 시간 초과 -> ios_base::sync_with_stdio(false), cin.tie(NULL) 로 해결
 1. Set 사용
 2. Vector 사용 + 이분 탐색
 */

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> V;

int getAns(int num, int l, int r) {
    if (l > r) return 0;
    int mid = (l + r) / 2;
    if (num == V[mid]) return 1;
    if (num > V[mid]) return getAns(num, mid + 1, r);
    if (num < V[mid]) return getAns(num, l, mid - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
    }

    sort(V.begin(), V.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        cout << getAns(tmp, 0, N - 1) << '\n';
    }

    return 0;
}