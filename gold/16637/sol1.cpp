/*
    submission : https://www.acmicpc.net/source/62246359

    3 8 7 9 2
     + * - *

    (3+8)*7 > 3+(8*7) 이라고 해서
    3 8 7을 (3+8)*7 로 계산하면 안된다.
    왜냐하면뒤에 있는 수와 먼저 계산을 할 수도 있기 때문. 3+8*(7-9)

    결국에는 다 해봐야 한다. => 완전탐색
    go함수의 구현도 쉽지는 않았음.

    시간복잡도 계산을 위해 go함수의 구조를 인덱스로 표기하면

                            (0)
                    (0 1)             (0 1 2)
            (1 2)    (1,2,3)     (2 3)      (2 3 4)
        (2 3) (2 3 4)
    ...


    time: O(2^n) <= 2^20

    2^20은 10^6과 비슷한값 대략 백만 정도가 나옴.
*/

#include <bits/stdc++.h>

using namespace std;

int n, last_idx;
int nums[20];
char ops[20];

int cal(int a, int b, char op)
{
    switch (op)
    {
    case '*':
        return a * b;
    case '+':
        return a + b;
    case '-':
        return a - b;
    }
}

int go(int idx, int num)
{
    if (idx == last_idx)
    {
        return num;
    }

    int val1 = go(idx + 1, cal(num, nums[idx + 1], ops[idx]));

    int val2 = -987654321;
    if (idx + 2 <= last_idx)
    {
        int tmp = cal(nums[idx + 1], nums[idx + 2], ops[idx + 1]);
        val2 = go(idx + 2, cal(num, tmp, ops[idx]));
    }

    return max(val1, val2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    last_idx = (n - 1) / 2;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            cin >> nums[i / 2];
        if (i % 2 == 1)
            cin >> ops[i / 2];
    }

    cout << go(0, nums[0]) << "\n";

    return 0;
}