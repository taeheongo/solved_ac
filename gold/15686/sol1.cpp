/*
    submission : https://www.acmicpc.net/source/62071121

    치킨집의 개수 = 최대 13개

    13C1 + 13C2 + 13C3 + ... + 13C13 = sum

    nCr = nCn-r 이기때문에

    13C1 = 13C12  = 13
    13C2 = 13C11 = 78
    13C3 = 13C10 = 286
    13C4 = 13C9 = 715
    13C5 = 13C8 = 1287
    13C6 = 13C7 = 1716

    합쳐도 5000이 안되고
    모든 집들에 대해서 루프를 돌려 치킨집의 모든 경우의 수에 대해서 치킨거리의 최소값을 구하면 된다.

    time:+ sum + N^2*sum = O(N^2 * sum)

    처음에 지도입력받는 부분 =  N^2
    치킨집의 조합의 합 = sum
    모든 집에 대해서 각 조합별 치킨거리 = N^2 * sum
    N^2의 최대값 = 2500
    sum <=5000
    N^2 * sum <= 12500000
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[50][50];
vector<pair<int, int>> chicken_list;
vector<pair<int, int>> home_list;
vector<vector<int>> vv;

void comb(vector<int> &v, int start, int k)
{
    if (v.size() == k)
    {
        vector<int> copy_v(v);
        vv.push_back(copy_v);

        return;
    }

    for (int i = start; i < chicken_list.size(); i++)
    {
        v.push_back(i);
        comb(v, i + 1, k);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];

            if (a[i][j] == 1)
                home_list.push_back({i, j});
            else if (a[i][j] == 2)
                chicken_list.push_back({i, j});
        }
    }

    for (int i = 1; i <= m; i++)
    {
        vector<int> v;
        comb(v, 0, i);
    }

    int ret = 10000;
    for (auto e : vv)
    {
        int sum = 0;

        for (auto home : home_list)
        {
            int tmp = 10000;
            for (int i : e)
            {
                int y1, y2, x1, x2;
                tie(y1, x1) = home;
                tie(y2, x2) = chicken_list[i];
                tmp = min(abs(y1 - y2) + abs(x1 - x2), tmp);
            }
            sum += tmp;
        }

        ret = min(ret, sum);
    }

    cout << ret << "\n";

    return 0;
}