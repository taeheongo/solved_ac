/*
    subission : https://www.acmicpc.net/source/64950688

    time: O(NlogN)

    정렬을 활용한 풀이

    주의할 점:
        보통은 백만단위 까지는 스택에 저장가능하나(문제마다 다름.)
        천만단위부터는 스택에 저장이 힘듬. 그래서 힙 메모리(vector)를 사용.
*/

#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<double> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 7; i++)
    {
        printf("%.3lf\n", v[i]);
    }

    return 0;
}