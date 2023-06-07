/*
    submission : https://www.acmicpc.net/source/61821420

    분할정복

    time: O(N^2)
*/

#include <bits/stdc++.h>

using namespace std;

int n;
const int N = 64;
int a[N][N];
// int cnt; // 디버깅

string go(int y, int x, int k)
{
    // cnt++; // 디버깅
    if (k == 1)
        return to_string(a[y][x]);

    k /= 2;
    string ret1 = go(y, x, k);
    string ret2 = go(y, x + k, k);
    string ret3 = go(y + k, x, k);
    string ret4 = go(y + k, x + k, k);

    if (ret1[0] != '(' && ret1 == ret2 && ret1 == ret3 && ret1 == ret4)
        return ret1;

    return "(" + ret1 + ret2 + ret3 + ret4 + ")";
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    cout << go(0, 0, n) << "\n";
    // cout << cnt << "\n";  // 디버깅

    return 0;
}

/*
시간복잡도 계산
지수법칙 : a^logb = b^loga

8         -> 85 = 64 + 16 + 4 + 1 = 1 * (4^(log(N)+1)) / (4-1) = 4/3 * N^2 => N^2
11110000
11110000
00011100
00011100
11110000
11110000
11110011
11110011



4       -> 21
1111
1111
1111
1111

2        -> 5
11
11

1        -> 1

An = n^2 + An-1 + 1

An - An-1 = n^2 + 1


*/