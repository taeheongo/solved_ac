/*
    submission : https://www.acmicpc.net/source/65440972

    time : O(N)

    2 pointer + cnt 배열 활용.(여기서는 개수 대신 boolean 배열을 활용.)

    에)
    8
    1 2 3 1 2 4 5 6

    l     r            -> 3개
      l     r          -> 3개
        l         r    -> 21개

    1 2 3
      2 3
        3
      2 3 1
        3 1
          1
        3 1 2 4 5 6 -> (6*7) / 2 = 21개
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ret;
int n, nums[100001];
bool d[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    int l = 1, r = 2;
    d[nums[l]] = 1;
    while (r <= n && l <= r)
    {
        if (d[nums[r]] == 0)
        {
            d[nums[r]] = !d[nums[r]];
            r++;
        }
        else
        {
            // printf("(%d, %d)\n", l, r);
            ret += r - l;
            d[nums[l]] = !d[nums[l]];
            l++;
        }
    }

    ret += (ll)(r - l) * (r - l + 1) / 2; // 주의 r-l은 최대 10^5개 ret은 최대 약 10^10까지 갈 수 있으므로 long long에 담아야 한다.
                                          // ret만 long long이 아니라 오른쪽의 계산식에서도 int끼리의 계산이 아니라 long long으로 형변환을 해줘서
                                          // long long형 끼리의 계산이 되게 해야함.
    cout << ret << "\n";

    return 0;
}