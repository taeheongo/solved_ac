/*
    submission : https://www.acmicpc.net/source/61909496

    brute force

    n의 최대값이 10000인데 10000을 넣어도 2666799 정도 박에 안나옴.
    보통 10000000 까지는 통과한다.(문제마다 안될 수도 있음.)
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main()
{
    cin >> n;
    int num = 666;

    while (true)
    {
        s = to_string(num);
        if (s.find("666") != string::npos)
        {
            n--;
        }
        if (n == 0)
            break;

        num++;
    }

    cout << num << "\n";

    return 0;
}