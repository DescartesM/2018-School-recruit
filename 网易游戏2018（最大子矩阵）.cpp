#include <iostream>
#include <vector>
using namespace std;
/*
INPUT:
4 4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

4 4
0 0 -2 -7
-2 9 2 -6
-1 -4 1 -4
-2 -1 8 0
OUTPUT:
15 15
Description:最大子矩阵和问题，最大子串问题扩展。二维映射一维，然后相同的DP思想。
*/
int main(int argc, char const *argv[])
{
    int m, n, x;
    cin >> m >> n;
    vector< vector<int> > vec;
    vec.resize(m); // m rows
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> x;
            vec[i].push_back(x); // n cols
        }
    }
    //2-D translate to 1-D
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            vec[j][i] = vec[j][i - 1] + vec[j][i];
        }
    }
    // same as the max sum of sub string.
    //first getMaxMatrix from zero-col to all-col
    int res = vec[0][0];
    for (int j = 0; j < n; ++j)
    {
        int f = vec[0][j];
        for (int i = 1; i < m; ++i)
        {
            if (f<0)
                f = vec[i][j];
            else
                f += vec[i][j];
            if (f > res)
                res = f;
        }
    }
    //second start i-col end j-col getmaxmatrix
    for (int i = 1; i < n; ++i)// start col
    {
        for (int j = 1; j < n && j >=i; ++j)// end col
        {
            int f = vec[0][j] - vec[0][i - 1];
            for (int k = 1; k < m; ++k) // 1-D DP
            {
                if (f<0)
                    f = vec[k][j] - vec[k][i - 1];
                else
                    f += vec[k][j] - vec[k][i - 1];
                if (f > res)
                    res = f;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}

