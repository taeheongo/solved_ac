/*
    std::rotate
        Performs a left rotation on a range of elements.
        Specifically, std::rotate swaps the elements in the range [first, last) in such a way that the elements in [first, middle) are placed
        after the elements in [middle, last) while the orders of the elements in both ranges are preserved.
*/

#include <bits/stdc++.h>

using namespace std;

void print(int b[9])
{
    for (int i = 0; i < 9; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
}

void print_v(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotate(a, a + 1, a + 9);
    print(a);

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotate(v.begin(), v.begin() + v.size() - 1, v.end());
    print_v(v);

    return 0;
}