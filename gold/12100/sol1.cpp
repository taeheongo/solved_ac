/*
    submission : https://www.acmicpc.net/source/65723078

    time: O(N^2)

    back tracking  + 구현 난이도 상
    이 문제에서 상하좌우로 블록들을 이동시킨다고해서 상하좌우로 블록들을 밀어버리는 작업(move)을 따로 짤 필요가 없다.
    한 방향으로 밀어버리는 함수를 짜고 -> move
    배열을 회전시켜서 다시 move를 해주면 된다. => roate90
    이렇게 5번의 depth를 거쳐서 최댓값을 구하면 된다. => get_max

    cnt
    5             북            동             남            서
    4      북  동   남   서
    3  북 동 남 서
    2
    1
    0 get_max()!
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;

struct Board
{
    int a[20][20];
    int _a[20][20];

    void rotate_90()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                _a[i][j] = a[n - 1 - j][i];
            }
        }

        swap(a, _a);
    }
    /*
        move 함수를 짜는 것이 어려움.
        move함수에서는 tmp[20][20] 이렇게 공간을 잡고 나중에 memcpy를 해도 되지만, 굳이 그럴 필요는 없다.
        idx가 -1부터 시작한다면 항상 idx < j 이기 때문.
        flag를 사용해서 a[i][idx]가 결정이 났는지 안 났는지 알 수 있다.
        블록은 한 턴에 1번밖에 못 합쳐지므로, a[i][idx] *= 2인 경우는 결정이 된 것.(= 합쳐질 가능성이 없다.) => flag = false;
        블록이 합쳐지지 않았다면 다음에 나오는 블록과 합쳐질 가능성이 있으므로 => flag = true;
    */
    void move()
    {
        for (int i = 0; i < n; i++)
        {
            int idx = -1;
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                // flag true면 a[i][idx]가 결정x, false면 결정 o
                if (a[i][j] == 0)
                    continue;

                if (flag && a[i][j] == a[i][idx])
                {
                    a[i][idx] *= 2;
                    flag = false;
                }
                else
                {
                    a[i][++idx] = a[i][j];
                    flag = true;
                }
            }

            for (int j = idx + 1; j < n; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    int get_max()
    {
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret = max(a[i][j], ret);
            }
        }

        return ret;
    }

    // debug
    void print()
    {
        cout << "k : " << ++k << "\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int go(int cnt, Board &brd)
{
    if (cnt == 0)
    {
        return brd.get_max();
    }

    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        Board tmp_brd = brd;
        tmp_brd.move();
        // tmp_brd.print(); // debug
        ret = max(ret, go(cnt - 1, tmp_brd));
        brd.rotate_90();
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Board brd;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> brd.a[i][j];
        }
    }

    cout << go(5, brd) << "\n";

    return 0;
}