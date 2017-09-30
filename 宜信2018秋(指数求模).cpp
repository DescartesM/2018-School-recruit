#include <iostream>   
using namespace std;
/*
INPUT:2,3
OUTPUT: 6
Description:n种颜色，w个盒子，相邻盒子球颜色相同则为一种情况，求有多少种情况。
考察指数求模，问题转化。
*/
typedef long long ll;
inline ll mi(ll a, ll b, ll mo)
{
    ll ans = 1;
    a %= mo;
    while (b)
    {
        if (b & 1) ans = ans*a%mo;
        b >>= 1;
        a = a*a%mo;
    }
    return ans;
}

int main(int argc, char* argv[])
{
    ll w, n;
    cin >> n >> w;
    ll mod = 100003;
    ll part1, part2, part3;
    part1 = mi(n, w, mod);
    part2 = mi(n-1, w, mod);
    part3 = mi(n-1, w-1, mod);
    ll ans = part1 - part2 - part3;
    if (ans < 0)
    {
        ans += mod;
    }

    printf("%lld", ans);
    system("PAUSE");
    return 0;
}