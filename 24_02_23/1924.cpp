/*
 ✅ baekjoon 1924
 문제 유형: 구현
 1월 1일 월요일
 1월 6일은? 6 % 7 = 6 -> 토요일
 1월 8일은? 8 % 7 = 1 -> 월요일
 2월 1일은? (31 + 1) % 7 = 4 -> 목요일
 */

#include <bits/stdc++.h>

using namespace std;

int x, y;
int numberOfDaysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string dayOfWeek[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {
    cin >> x >> y;

    int days = y;
    for (int i = 1; i < x; i++) {
        days += numberOfDaysOfMonth[i - 1];
    }

    cout << dayOfWeek[days % 7] << '\n';
    return 0;
}