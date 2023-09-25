/*
    submission : https://www.acmicpc.net/source/67175897

    구현 문제
    규칙을 찾아내는 것이 어려움.
*/

#include <bits/stdc++.h>

using namespace std;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
const int R = 101;
const int C = 101;

int n, y, x, d, g, ret;
int a[101][101];

// 드래곤 커브 생성
void create_dragon_curve(int y, int x, int d, int g) {
    vector<int> v;
    v.push_back(d);
    a[y][x] = 1;

    for (int i = 1; i <= g; i++) {
        int size = 1 << i;
        for (int i = 0; i < size; i++) {
            v.push_back(v[i]);
        }

        reverse(v.begin(), v.begin() + size);

        for (int i = 0; i < size; i++) {
            v[i] = (v[i] + 1) % 4;
        }
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        int ny = y + dy[v[i]];
        int nx = x + dx[v[i]];

        a[ny][nx] = 1;
        y = ny;
        x = nx;
    }
}

// debug
void print() {
    printf("\n");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        create_dragon_curve(y, x, d, g);
        // print(); // debug
    }

    for (int i = 0; i < R - 1; i++) {
        for (int j = 0; j < C - 1; j++) {
            if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}