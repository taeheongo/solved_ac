/*
    submission : https://www.acmicpc.net/source/66444592

    time : O(4^n)

    그래프를 순회하려면 인접리스트를 만들어야 하는데 그래프의 노드가 가진 값이
   id로서 역할을 하지 못한다.(22, 28 이 중복) id의 역할을 할 수 있는 무언가를
   만들어야 하기 위해 vector에 노드를 저장하고 vector의 인덱스를 id로 활용함.
   그 이후에는 구현 + 백트랙킹.
*/

#include <bits/stdc++.h>

const int TURN = 10;

using namespace std;

vector<int> adj[54];
vector<int> v(54);
int a[10];
int m[4];
void add(int here, int there) { adj[here].push_back(there); }

void set_map() {
  vector<int> nums = {0,  2,  4,  6,  8,  10, 12, 14, 16, 18, 20,
                      22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13,
                      16, 19, 25, 30, 35, 22, 24, 28, 27, 26};

  for (int i = 0; i < nums.size(); i++) v[i] = nums[i];

  for (int i = 0; i <= 19; i++) add(i, i + 1);
  add(5, 21);
  add(21, 22);
  add(22, 23);
  add(23, 24);
  add(24, 25);
  add(25, 26);
  add(26, 20);
  add(20, 50);

  add(10, 27);
  add(27, 28);
  add(28, 24);

  add(15, 29);
  add(29, 30);
  add(30, 31);
  add(31, 24);
}

int go(int here, int num) {
  if (here == 50) return 50;
  if (adj[here].size() >= 2) {
    here = adj[here][1];
    num--;
  }

  if (num) {
    while (num-- && here != 50) here = adj[here][0];
  }

  return here;
}

bool check(int m_idx, int v_idx) {
  if (v_idx == 50) return false;

  for (int j = 0; j < 4; j++) {
    if (j == m_idx) continue;

    if (m[j] == v_idx) return true;
  }

  return false;
}

int play(int turn) {
  if (turn == 0) return 0;

  int ret = 0;
  for (int i = 0; i < 4; i++) {
    int v_idx = go(m[i], a[TURN - turn]);

    if (check(i, v_idx)) continue;

    int tmp_idx = m[i];
    m[i] = v_idx;
    ret = max(ret, v[v_idx] + play(turn - 1));
    m[i] = tmp_idx;
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 10; i++) cin >> a[i];

  set_map();
  cout << play(TURN) << "\n";

  return 0;
}
