/*
submission : https://www.acmicpc.net/source/61451315

key가 26개의 정수이므로 맵보다는 배열.
*/
#include <bits/stdc++.h>

using namespace std;

int alphabet[26];
string s;

int main()
{
    cin >> s;

    for (int i = 0; i < (int)s.size(); i++)
    {
        alphabet[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " ";
    }

    return 0;
}