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

// Think in DP, the Time complexity is O(n^2)
//dp[i] = max(1, dp[j] + 1); j<i && a[j] <= a[i]
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

// method two
// arr is the origin array, ans is an array for
// saving the longest increasing array's last element 
// the Time complexity is O(nlogn)
ans[1] = arr[1];
len = 1;
for (int i = 2; i <= n; ++i)
{
    if (arr[i] > ans[len])
    {
        ans[++len] = arr[i]; 
    }
    else{
        int pos = lower_bound(ans,ans+len,arr[i])-ans; // find the lower bound binary search
        ans[pos] = arr[i]; 
    }
}
