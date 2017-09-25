#include <iostream> 
#include <vector>
#include <algorithm>
#define MAXVALUE 6  
using namespace std;
/*
INPUT: 2, 6
OUTPUT: 13/18
Description: n个骰子，投掷后如果值累加大于k，则获胜。计算获胜概率，用最简分数表示。
n<=15, k<150
*/
long long sumOfNDice(int n, int k) {
    if (n < 1) {
        return -1;
    }
    // initial
    vector<vector<int>>pProbabilities;
    pProbabilities.resize(2);
    for (int i = 0; i < 2; ++i)
        pProbabilities[i].resize(MAXVALUE*n + 1);
    int flag = 1;
    for (int i = 0; i < MAXVALUE*n + 1; ++i) {
        pProbabilities[flag][i] = 0;
        pProbabilities[1 - flag][i] = 0;
    }
    for (int i = 1; i <= MAXVALUE; ++i) {// 当骰子数为1时  
        pProbabilities[flag][i] = 1;
    }
    for (int k = 2; k <= n; ++k) {// 当骰子数为2-n时  
        for (int i = k; i <= MAXVALUE*k; ++i) {
            pProbabilities[1 - flag][i] = 0;
            for (int j = 1; j <= i && j <= MAXVALUE; ++j) {
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
            }
        }
        flag = 1 - flag;
    }
    long long ans = 0;
    for (int i = k; i <= MAXVALUE*n; ++i) {
        ans += pProbabilities[flag][i];
    }
    return ans;
}
int main(int argc, char ** argv)
{
    int n, k;
    long long base;
    cin >> n >> k;
    long long ans, save1, save2;
    ans = sumOfNDice(n, k);
    base = pow(6, n);
    save1 = ans;
    save2 = base;
    long long temp;// 辗转相除法
    while (ans)
    {
        temp = base%ans;
        base = ans;
        ans = temp;
    }
    save1 = save1 / base;
    save2 = save2 / base;
    printf("%lld/", save1);
    printf("%lld\n", save2);
    system("pause");
    return 0;
}