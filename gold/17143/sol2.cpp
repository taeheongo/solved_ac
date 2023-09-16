/*
    submission : https://www.acmicpc.net/source/66700814

    solution1과 논리는 같으나 move_fish부분에서 xor연산을 사용해서
    코드도 짧아지고 간지가 난다.

    전체적인 time complexity는 solution 1과 동일.
*/

#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};

struct A {
  int y, x, s, d, z;
  bool death;
};

int r, c, m, ret;
int a[104][104];
vector<A> v;
int y, x, s, d, z;

void move_fish() {
  for (auto& e : v) {
    if (e.death) continue;

    a[e.y][e.x] = -1;

    int d = e.d, s = e.s, y = e.y, x = e.x;
    int ny, nx;
    while (1) {
      ny = y + s * dy[d];
      nx = x + s * dx[d];

      if (0 <= ny && ny < r && 0 <= nx && nx < c) break;

      switch (d) {
        case 0:
          s -= y;
          y = 0;
          break;
        case 1:
          s -= r - 1 - y;
          y = r - 1;
          break;
        case 2:
          s -= c - 1 - x;
          x = c - 1;
          break;
        case 3:
          s -= x;
          x = 0;
          break;
      }

      d ^= 1;
    }

    e.y = ny;
    e.x = nx;
    e.d = d;
  }
}

void print() {
  cout << "\n";
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int output = a[i][j] == -1 ? 0 : v[a[i][j]].z;
      cout << output << " ";
    }
    cout << "\n";
  }
}

void update() {
  for (int i = 0; i < v.size(); i++) {
    if (v[i].death) continue;

    int y = v[i].y;
    int x = v[i].x;

    if (a[y][x] == -1) {
      a[y][x] = i;
    } else {
      if (v[a[y][x]].z < v[i].z) {
        v[a[y][x]].death = true;
        a[y][x] = i;
      } else {
        v[i].death = true;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&a[0][0], &a[0][0] + 104 * 104, -1);

  cin >> r >> c >> m;
  while (m--) {
    cin >> y >> x >> s >> d >> z;  // y, x, 속력, 방향, 크기

    if (d <= 2)
      s %= 2 * (r - 1);
    else
      s %= 2 * (c - 1);

    v.push_back({y - 1, x - 1, s, d - 1, z, false});
    a[y - 1][x - 1] = v.size() - 1;
  }

  // 디버그
  // print();
  // cout << "ret :  " << ret << "\n";
  for (int x = 0; x < c; x++) {
    // 물고기 낚시
    int y = 0;
    for (; y < r; y++) {
      if (a[y][x] != -1) break;
    }

    if (y != r) {
      ret += v[a[y][x]].z;
      v[a[y][x]].death = true;
      a[y][x] = -1;
    }

    // 물고기 이동
    move_fish();

    // 물고기 중복체크
    update();

    // 디버그
    // print();
    // cout << "ret :  " << ret << "\n";
  }

  cout << ret << "\n";

  return 0;
}