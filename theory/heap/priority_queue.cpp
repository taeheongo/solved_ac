/*
    참조 : https://en.cppreference.com/w/cpp/container/priority_queue
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};

    priority_queue<int> q;

    for (int i = 0; i < 7; i++)
    {
        q.push(nums[i]);
    }

    while (q.size())
    {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}

/*
    최대 힙
    {1, 2, 3, 4, 5, 6, 7}

                    7
            4               6
        1       3       2       5

                    1

    {7, 4, 6, 1, 3, 2, 5}
*/