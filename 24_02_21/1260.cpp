/*
 ✅ baekjoon 1260
 문제 유형: BFS, DFS
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, V;

int vertices[1001];
bool visitedVertices[1001];

bool graph[1001][1001];
bool visitedGraph[1001][1001];

void DFS(int index) {
    visitedVertices[index] = true;
    cout << vertices[index] << ' ';

    for (int i = 1; i <= N; i++) {
        if (visitedGraph[index][i]) {
            visitedGraph[index][i] = false;
            visitedGraph[i][index] = false;
            if (visitedVertices[i]) continue;
            DFS(i);
        }
    }
}

void BFS() {
    queue<int> Q;
    Q.push(V);

    while (!Q.empty()) {
        int index = Q.front();
        visitedVertices[index] = false;
        cout << index << ' ';
        Q.pop();

        for (int i = 1; i <= N; i++) {
            if (visitedGraph[index][i]) {
                visitedGraph[index][i] = false;
                visitedGraph[i][index] = false;
                if (visitedVertices[i]) continue;
                visitedVertices[i] = true;
                Q.push(i);
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    for (int i = 1; i <= N; i++) {
        vertices[i] = i;
    }

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    fill(visitedVertices, visitedVertices + 1001, false);
    copy(&graph[0][0], &graph[0][0] + 1001 * 1001, &visitedGraph[0][0]);
    DFS(V);
    cout << '\n';

    fill(visitedVertices, visitedVertices + 1001, false);
    copy(&graph[0][0], &graph[0][0] + 1001 * 1001, &visitedGraph[0][0]);
    BFS();
    cout << '\n';

    return 0;
}