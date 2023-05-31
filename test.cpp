#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    s = "hello world\n";

    string s2 = s.substr(s.size() - 1, 5);

    cout << s2;

    return 0;
}