/*
    submission : https://www.acmicpc.net/source/61516825

    반례 조심.
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string p, f, b;

int main()
{
    cin >> n;
    cin >> p;

    int pos = p.find("*");
    f = p.substr(0, pos);
    b = p.substr(pos + 1);

    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s.size() < f.size() + b.size()) // 반례
        {
            cout << "NE\n";
            continue;
        }

        if (s.substr(0, f.size()) != f)
        {
            cout << "NE\n";
            continue;
        }

        if (s.substr(s.size() - b.size()) != b)
        {
            cout << "NE\n";
            continue;
        }

        cout << "DA\n";
    }

    return 0;
}