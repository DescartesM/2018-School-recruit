#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 10005
using namespace std;
/*
INPUT：
5
15 0
0 28
25 0
55 0
0 127
OUTPUT：5
INPUT：
6
0 0
2 4
4 0
1 2
3 2
2 1
OUTPUT：5
Description: 平面n个点，最少连接几条边，包围所有点。
Solution: 遍历，判断其他点是否在直线一侧。每个点可以visit2次，2次后退出遍历的集合。
        如果共线则连接最短的线段，并更新点的位置后再更新visited。
        updating...
*/
int main() {
    int n;
    cin >> n;
    int pos[MAX][2] = { 0 };
    int visited[MAX] = { 0 };
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        pos[i][0] = x;
        pos[i][1] = y;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visited[i]<2 && visited[j]<2 && i != j)
            {
                // flag used to judge if on one side
                int flag1 = 0;
                int flag2 = 0;
                int yjn = j;
                for (int k = 0; k < n; ++k)
                {
                    if (k != i && k != j)
                    {
                        int temp;
                        
                        temp = (pos[i][0] - pos[k][0])*(pos[j][1] - pos[k][1]) - (pos[i][1] - pos[k][1])*(pos[j][0] - pos[k][0]);
                        if (temp > 0)
                            flag1 = 1;
                        else if (temp < 0)
                            flag2 = 1;
                        else if (temp == 0) // find the min line
                        {
                            if (abs(pos[i][0] - pos[k][0]) < abs(pos[i][0] - pos[j][0]) ||
                                abs(pos[i][1] - pos[k][1]) < abs(pos[i][1] - pos[j][1]))
                                yjn = k;
                        }
                    }
                }
                if (flag1 != flag2) // one side update the visited
                {
                    visited[i] += 1;
                    visited[yjn] += 1;
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);

    system("PAUSE");
    return 0;
}