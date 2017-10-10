#include <iostream>
#include <vector>
using namespace std;
/*
INPUT: 3 15
OUTPUT:
1 5 9
1 6 8
2 4 9 
2 5 8
2 6 7
3 4 8
3 5 7
4 5 6
Description: 输入n，k。1-9里面选k个数，和为n。求可能的种类有多少？没有输出None
*/
vector<vector<int> >  result;
vector<vector<int> > combine2(int n, int m, vector<int> b, int target) {
    for (int i = n; i >= m; i--) {

        b[m - 1] = i;

        if (m > 1) {
            combine2(i - 1, m - 1, b, target);
        }
        else {
            // m == 1, 输出一个组合    
            int sum = 0;
            for (int i = 0; i < b.size(); ++i)
            {
                sum += b[i];
            }
            if (sum == target)
            {
                result.push_back(b);
            }

        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
    int k, n;
    cin >> k >> n;
    if (k == 0 || n < k*(k+1)/2 || n > k*(19-k)/2) {
        printf("None");
        return 0;
    }
    vector<int> res;

    res.resize(k);
    result = combine2(9, k, res, n);
    if (result.size() == 0)
    {
        printf("None");
        return 0;
    }
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < k - 1; ++j)
        {
            cout << result[i][j] << ' ';
        }
        cout << result[i][k-1] << endl;
    }

    system("PAUSE");
    return 0;
}
