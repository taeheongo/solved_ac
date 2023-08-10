#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 7;

void print(int nums[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

void print_v(vector<int> v)
{
    for (int e : v)
    {
        cout << e << " ";
    }
    cout << "\n";
}

int main()
{
    int nums[N] = {1, 2, 3, 4, 5, 6, 7};
    make_heap(&nums[0], &nums[0] + N);

    print(nums);

    int nums2[N] = {1, 2, 3, 4, 5, 6, 7};
    int nums3[N] = {0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 7; i++)
    {
        nums3[i] = nums2[i];
        push_heap(&nums3[0], &nums3[0] + 1 + i);
        print(nums3);
    }

    vector<int> v{1, 2, 3, 4, 5, 6};
    make_heap(v.begin(), v.end());
    print_v(v);

    v.push_back(7);
    push_heap(v.begin(), v.end());
    print_v(v);

    return 0;
}
