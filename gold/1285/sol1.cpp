/*
    submission : https://www.acmicpc.net/source/62724203

    잘못된 논리로 인한 실패.

    3
    HHT
    THH
    THT

    행과 행은 서로 독립적이라서 행을 먼저 뒤집고,
    그 다음에 열을 뒤집으려고 했다.

    그런데 행과 행은 독립적이지만 행은 n개의 열과 종속적이다.
    i번째 행을 뒤집냐 안 뒤집냐에 따라 1개이상의 열이 뒤집힐 수도 안 뒤집힐 수도 있는 것.
    이 상관관계를 무시해서 생긴 오류.
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 20;
const int INF = 987654321;

int n, ret = INF, total_cnt;
char a[max_n + 4][max_n + 4];
char a_origin[max_n + 4][max_n + 4];
pair<int, int> cnt[max_n + 4];
pair<int, int> cnt_origin[max_n + 4];

void print()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout << "total_cnt : " << total_cnt << "\n";
}

void check_row()
{
    for (int i = 0; i < n; i++)
    {
        if (cnt[i].first > n / 2)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 'T')
                {
                    a[i][j] = 'H';
                    cnt[j].second--;
                }
                else
                {
                    a[i][j] = 'T';
                    cnt[j].second++;
                }
            }

            total_cnt -= cnt[i].first;
            cnt[i].first = n - cnt[i].first;
            total_cnt += cnt[i].first;
        }
    }
}

void check_col()
{
    for (int j = 0; j < n; j++)
    {
        if (cnt[j].second > n / 2)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i][j] == 'T')
                {
                    a[i][j] = 'H';
                    cnt[i].first--;
                }
                else
                {
                    a[i][j] = 'T';
                    cnt[i].first++;
                }
            }

            total_cnt -= cnt[j].second;
            cnt[j].second = n - cnt[j].second;
            total_cnt += cnt[j].second;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a_origin[i][j];
            if (a_origin[i][j] == 'T')
            {
                cnt_origin[i].first++;
                cnt_origin[j].second++;
                total_cnt++;
            }
        }
    }

    ret = total_cnt;

    memcpy(a, a_origin, sizeof(a));
    memcpy(cnt, cnt_origin, sizeof(cnt));

    // print();

    check_row();
    check_col();

    // print();

    int tmp = ret;
    ret = min(total_cnt, ret);
    total_cnt = tmp;

    memcpy(a, a_origin, sizeof(a));
    memcpy(cnt, cnt_origin, sizeof(cnt));

    // print();

    check_col();
    check_row();

    ret = min(total_cnt, ret);

    // print();

    cout << ret << "\n";

    return 0;
}