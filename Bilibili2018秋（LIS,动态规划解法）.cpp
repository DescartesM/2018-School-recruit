#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
input: 2 4 1 3 5;
output: 3;
input: 1 2 3 4 5;
output: 5;
可以去除数组中任意数字，实现不递减数组，使这个不递减数组最长。
*/


int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> input;
    vector<int> dp;
    dp.resize(N,1);
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        input.push_back(x);
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (input[i] >= input[j])
            {
                dp[i] = max(1, dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }
    printf("%d\n", ans);
    system("PAUSE");
    return 0;
}