#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 1e5+5;

int a[MAXN];
LL x, y;
LL n, m;
LL sum;
LL ans;
LL s, d;

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL ans = exgcd(b, a%b, x, y);
    LL t = x;
    x = y;
    y = t - a/b*y;
    return ans;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        sum %= m;
    }
    
    x = n;
    y = n*(n+1)/2;

    s = 1; d = 1;

    x = exgcd(x, y, s, d);
    y = sum;

    

    if(s < 0) s = s % m + m;
    if(d < 0) d = d % m + m;
    if(s > m) s %= m;
    if(d > m) d %= m;
    
    
    // cout << x << " " << y << endl;
    // cout << s << " " << d << endl;

    LL tmp = 1, tmp2 = 1;

    ans = exgcd(x, m, tmp, tmp2);

    tmp += m;
    
    s = s * tmp % m; d = d * tmp % m;
    // cout << ans << endl;
    int k = ((m - sum - 1) / ans + 1);

    s = k * s % m; d = k * d % m;

    ans = k * ans + sum;
    ans %= m;

    cout << ans << endl;
    cout << s << " " << d << endl;
    




    return 0;
}