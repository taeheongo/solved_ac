/*
submission : https://www.acmicpc.net/source/61444409

순열을 이용한 풀이

순서가 중요하지 않기 때문에 순열로 풀 필요는 없지만 순열로 풀어도 상관은 없다.
9P7 만큼의 경우의 수중에서
합이 100 되는 경우 하나를 출력하면 되기 때문.
recursive한 방식으로 구현.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> v(9, 0);
bool catched = false;

void go(int n, int r, int depth)
{
    if (depth == r)
    {
        int sum = accumulate(v.begin(), v.begin() + 7, 0);
        if (sum == 100)
        {
            catched = true;
        }
        return;
    }

    for (int i = depth; i < 9; i++)
    {
        swap(v[i], v[depth]);
        go(n, r, depth + 1);
        if (catched == true)
            break;
        swap(v[i], v[depth]);
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> v[i];
    }

    go(9, 7, 0);

    sort(v.begin(), v.begin() + 7);

    for (int i = 0; i < 7; i++)
    {
        cout << v[i] << "\n";
    }

    return 0;
}