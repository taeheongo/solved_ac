/*
    submission : https://www.acmicpc.net/source/65440865

    sol 1과 논리는 같음. boolean 배열이 아니라 cnt배열을 활용.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ret;
int n;
int nums[100001], cnt[100001];

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
    cnt[nums[1]]++;
    while (r <= n && l <= r)
    {
        if (cnt[nums[r]] == 0)
        {
            cnt[nums[r++]]++;
        }
        else
        {
            // printf("(%d, %d)\n", l, r);
            ret += r - l;
            cnt[nums[l++]]--;
        }
    }

    ret += (ll)(r - l) * (r - l + 1) / 2;
    cout << ret << "\n";

    return 0;
}