#include <bits/stdc++.h>

using namespace std;

int n, ret_max = -1000000001, ret_min = 1000000001;
int a[11];
int _plus, _minus, _mul, _div;

void go(int a_idx, int cur, int plus, int minus, int mul, int div) {
  if (a_idx == n) {
    ret_max = max(ret_max, cur);
    ret_min = min(ret_min, cur);

    return;
  }

  if (plus) go(a_idx + 1, cur + a[a_idx], plus - 1, minus, mul, div);
  if (minus) go(a_idx + 1, cur - a[a_idx], plus, minus - 1, mul, div);
  if (mul) go(a_idx + 1, cur * a[a_idx], plus, minus, mul - 1, div);
  if (div) go(a_idx + 1, cur / a[a_idx], plus, minus, mul, div - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> _plus;
  cin >> _minus;
  cin >> _mul;
  cin >> _div;

  go(1, a[0], _plus, _minus, _mul, _div);

  cout << ret_max << "\n";
  cout << ret_min << "\n";

  return 0;
}