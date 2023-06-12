/*
    submission : https://www.acmicpc.net/source/61978571

    짝짓기 문제 => 짝짓기 문제는 보통 스택으로 많이 풀림.

    1. brute force
        n의 최댓값은 1,000,000
        배열의 값을 루프를 돌며 nge[i]를 구하면 n^2인데.
        당연히 이렇게 풀면 시간 초과.

    2. stack

        O(N)에 푸는 방법이 있다.
        어떤 두 수의 대소관계를 비교했으면 다시 비교하지 않게 어떤 자료구조에 저장해야한다.
        그렇게 해야 O(N^2)을 피할 수 있다.
        여기까지는 스택이 아니라 큐여도 상관없다고 생각 할 수 있지만.
        그 다음 수와 비교할 때 반드시 작은 값부터 비교해야 하므로 스택이어야 한다.

        4
        5 2 1 3

        stack : 5 2 1

        3이 1,2보다 크니까

        nge : -1 3 3 -1
        stack: 5 3
        이렇게 nge가 바뀌고 5는 여전히 3보다 크니까 -1

        이렇듯 스택에는 이전에 넣은 값보다 더 작은 값이 들어갈 수 밖에 없다. (5 2 1)
        그리고 스택의 top부터 비교하면 자연스럽게 스택의 가장 작은 값부터 비교 가능.

        time: O(N + N) = O(N)
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000004], nge[1000004];
stack<int> stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    memset(nge, -1, sizeof(nge));

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (stk.size() && a[stk.top()] < a[i])
        {
            nge[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << nge[i] << " ";
    }

    return 0;
}