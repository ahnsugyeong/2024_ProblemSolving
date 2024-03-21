/*

 행이나 열이 타일로 가득찬 경우와 연한 칸에 블록이 있는 경우가 동시에 발생할 수 있다.
 이 경우에는 행이나 열이 타일로 가득 찬 경우가 없을 때까지 점수를 획득하는 과정이 모두 진행된 후, 연한 칸에 블록이 있는 경우를 처리해야 한다.

 블록은 보드에 놓인 이후에 다른 블록과 합쳐지지 않는다.
 블록을 놓은 위치가 순서대로 주어졌을 때, 얻은 점수와 초록색 보드와 파란색 보드에 타일이 있는 칸의 개수를 모두 구해보자.


 t = 1: 크기가 1×1인 블록을 (x, y)에 놓은 경우
 t = 2: 크기가 1×2인 블록을 (x, y), (x, y+1)에 놓은 경우
 t = 3: 크기가 2×1인 블록을 (x, y), (x+1, y)에 놓은 경우

*/

#include <bits/stdc++.h>

using namespace std;

bool blue[6][4];
bool green[6][4];

void print() {
    printf("=== blue ===\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (blue[i][j]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }

    printf("\n=== green ===\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }


}

int getBlueIdx(int x) {
    for (int i = 0; i < 6; i++) {
        if (blue[i][x]) return i - 1;
    }
    return 5;
}

int getGreenIdx(int y) {
    for (int i = 0; i < 6; i++) {
        if (green[i][y]) return i - 1;
    }
    return 5;
}

void removeLineOfBlue(int idx) {
    for (int i = idx; idx >= 0; idx--) {
        for (int j = 0; j < 4; j++) {
            blue[i][j] = blue[i + 1][j];
        }
    }
}

void removeLineOfGreen(int idx) {
    for (int i = idx; idx >= 0; idx--) {
        for (int j = 0; j < 4; j++) {
            green[i][j] = green[i + 1][j];
        }
    }
}

int getScore() {
    int score = 0;
    for (int i = 2; i < 6; i++) {
        int blueCnt = 0;
        int greenCnt = 0;

        for (int j = 0; j < 4; j++) {
            if (blue[i][j]) blueCnt++;
            if (green[i][j]) greenCnt++;
        }
        if (blueCnt == 4) {
            removeLineOfBlue(i);
            score++;
        }
        if (greenCnt == 4) {
            removeLineOfGreen(i);
            score++;
        }
    }

}

void processSpecialBlock() {
    // blue
    int blueFlag = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (blue[i][j]) {
                blueFlag++;
                break;
            }
        }
    }

    // green
    int greenFlag = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j]) {
                greenFlag++;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int ans = 0;
    while (N--) {

        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) { // 크기가 1×1인 블록을 (x, y)에 놓은 경우
            // blue -> x 영향
            int blueIdx = getBlueIdx(x);
            blue[blueIdx][x] = true;

            // green -> y 영향
            int greenIdx = getGreenIdx(x);
            green[greenIdx][y] = true;

        } else if (t == 2) {  // t = 2: 크기가 1×2인 블록을 (x, y), (x, y+1)에 놓은 경우
            int blueIdx = getBlueIdx(x);
            blue[blueIdx][x] = true;
            blue[blueIdx - 1][x] = true;

            int greenIdx = min(getGreenIdx(y), getGreenIdx(y + 1));
            green[greenIdx][y] = true;
            green[greenIdx][y + 1] = true;

        } else if (t == 3) {  // t = 3: 크기가 2×1인 블록을 (x, y), (x+1, y)에 놓은 경우
            int blueIdx = min(getBlueIdx(x), getBlueIdx(x + 1));
            blue[blueIdx][x] = true;
            blue[blueIdx][x + 1] = true;

            int greenIdx = getGreenIdx(y);
            green[greenIdx][y] = true;
            green[greenIdx - 1][y] = true;

        }

        print();
        ans += getScore();
        processSpecialBlock();
    }

    cout << ans << '\n';


    return 0;
}