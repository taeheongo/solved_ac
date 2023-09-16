/*
    submission : https://www.acmicpc.net/source/66695573

    구현이 빡센 문제.
    물고기 이동을 반복문으로 1칸씩 가면 최대 c * m * s = 10^10 정도가 걸린다.
        r, c <= 100
        m = r*c <= 100000
        s <= 1000
    이 부분을 구현하는게 어려운 문제.
    if문으로 짜서 조금 비슷한 로직을 일일이 짰다.

    time : c * m * max(2*(r-1), 2*(c-1))
*/

#include <bits/stdc++.h>

using namespace std;

struct A {
  int y, x, s, d, z;
  bool death = false;
};

int r, c, m, ret;
int a[104][104];
vector<A> v;
int y, x, s, d, z;

void del_fish(int idx, int y, int x) {
  v[idx].death = true;
  a[y][x] = -1;
}

void move_fish() {
  for (auto& e : v) {
    if (e.death) continue;

    a[e.y][e.x] = -1;

    switch (e.d) {
      case 1:
        if (e.y > e.s) {
          e.y -= e.s;
        } else {
          int cnt = (e.s - e.y) / (r - 1);
          int rem = (e.s - e.y) % (r - 1);

          if (cnt % 2 == 0) {
            e.y = rem;
            e.d = 2;
          } else {
            e.y = r - 1 - rem;
          }
        }
        break;
      case 2:
        if (r - 1 - e.y > e.s) {
          e.y += e.s;
        } else {
          int cnt = (e.s - (r - 1 - e.y)) / (r - 1);
          int rem = (e.s - (r - 1 - e.y)) % (r - 1);

          if (cnt % 2 == 0) {
            e.y = r - 1 - rem;
            e.d = 1;
          } else {
            e.y = rem;
          }
        }
        break;
      case 3:
        if (c - 1 - e.x > e.s) {
          e.x += e.s;
        } else {
          int cnt = (e.s - (c - 1 - e.x)) / (c - 1);
          int rem = (e.s - (c - 1 - e.x)) % (c - 1);

          if (cnt % 2 == 0) {
            e.x = c - 1 - rem;
            e.d = 4;
          } else {
            e.x = rem;
          }
        }
        break;
      case 4:
        if (e.x > e.s) {
          e.x -= e.s;
        } else {
          int cnt = (e.s - e.x) / (c - 1);
          int rem = (e.s - e.x) % (c - 1);

          if (cnt % 2 == 0) {
            e.x = rem;
            e.d = 3;
          } else {
            e.x = c - 1 - rem;
          }
        }
        break;
    }
  }
}

void print() {
  cout << "\n";
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << v[a[i][j]].z << " ";
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
    cin >> y >> x >> s >> d >> z;  // y, x, 속력, 방향, 크
    v.push_back({y - 1, x - 1, s, d, z});
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
      del_fish(a[y][x], y, x);
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