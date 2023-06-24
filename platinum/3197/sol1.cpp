/*
    submission : https://www.acmicpc.net/source/62435625

    문제의 단순화 => 백조1에서 백조2를 찾는 과정이지만 백조1과 백조2이 속해 있는 component를 다 관리할 필요없이
    둘중 하나만 관리하면 된다.

    time: O(r*c)

        r * c <= 1500 * 1500 = 약 2200000

        while(move_swan()){
            melt()
        }

        최대 3 * r * c
*/

#include <bits/stdc++.h>

using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};
const int M = 1500;

int r, c, day, swan_y, swan_x, y, x;
char a[M + 4][M + 4];
bool visited_water[M + 4][M + 4], visited_swan[M + 4][M + 4];

queue<pair<int, int>> q_swan, q_swan_tmp;
queue<pair<int, int>> q_water, q_water_tmp;

bool move_swan()
{
    while (q_swan.size())
    {
        tie(y, x) = q_swan.front();
        q_swan.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > r || nx < 0 || nx > c || visited_swan[ny][nx])
                continue;

            visited_swan[ny][nx] = 1;

            switch (a[ny][nx])
            {
            case 'L':
                return true;
            case '.':
                q_swan.push({ny, nx});
                break;
            case 'X':
                q_swan_tmp.push({ny, nx});
                break;
            }
        }
    }

    return false;
}

void melt()
{
    while (q_water.size())
    {
        tie(y, x) = q_water.front();
        q_water.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (a[ny][nx] == 'X')
            {
                a[ny][nx] = '.';
                visited_water[ny][nx] = 1;
                q_water_tmp.push({ny, nx});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    string s;
    for (int i = 0; i < r; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            a[i][j] = s[j];

            if (s[j] == 'L' || s[j] == '.')
            {
                visited_water[i][j] = 1;
                q_water.push({i, j});

                if (s[j] == 'L')
                {
                    swan_y = i;
                    swan_x = j;
                }
            }
        }
    }

    visited_swan[swan_y][swan_x] = 1;
    q_swan.push({swan_y, swan_x});

    while (!move_swan())
    {
        melt();
        swap(q_swan, q_swan_tmp);
        swap(q_water, q_water_tmp);
        day++;
    }

    cout << day << "\n";

    return 0;
}