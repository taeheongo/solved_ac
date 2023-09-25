/*
    submission : https://www.acmicpc.net/source/67176481

    먼저 4방향의 0~10세대별 방향을 구한다.
*/

#include <bits/stdc++.h>

using namespace std;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
const int R = 101;
const int C = 101;

int n, y, x, d, g, ret;
int a[101][101];
vector<int> v[4][11];

void make_direction() {
    for (int d = 0; d < 4; d++) {
        v[d][0].push_back(d);
        v[d][1].push_back((d + 1) % 4);

        for (int i = 2; i <= 10; i++) {
            int size = v[d][i - 1].size();

            for (int j = size - 1; j >= 0; j--) {
                v[d][i].push_back((v[d][i - 1][j] + 1) % 4);
            }

            for (int j = 0; j < size; j++) {
                v[d][i].push_back(v[d][i - 1][j]);
            }
        }
    }
}

// 드래곤 커브 생성
void create_dragon_curve(int y, int x, int d, int g) {
    a[y][x] = 1;
    for (int i = 0; i <= g; i++) {
        for (int dir : v[d][i]) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            a[ny][nx] = 1;
            y = ny;
            x = nx;
        }
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
    make_direction();
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        create_dragon_curve(y, x, d, g);
        print();  // debug
    }

    for (int i = 0; i < R - 1; i++) {
        for (int j = 0; j < C - 1; j++) {
            if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}