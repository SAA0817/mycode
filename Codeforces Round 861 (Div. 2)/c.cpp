#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 405;
const int mod = 1e9+7;

int t;
LL l, r;
LL a[30], b[30];
LL tmp[30];
LL ans = 20;
LL num;
int cnt = 0;

LL getnum()
{
    LL res = 0;
    for(int i = cnt; i >= 1; i--)
    {
        res *= 10;
        res += tmp[i];
    }
    return res;
}

void solve(int i, bool up, bool down, LL maxnum, LL minnum)
{
    if(i == 0)
    {
        // cout << getnum() << " " << maxnum << " " << minnum << endl;
        if(maxnum - minnum < ans) 
        {
            ans = maxnum - minnum;
            num = getnum();
        }
        return;
    }

    if(up && down && a[i] == b[i])
    {
        tmp[i] = a[i];
        solve(i-1, up, down, max(maxnum, a[i]), min(minnum, a[i]));
    }

    else if(!up && !down)
    {
        tmp[i] = tmp[i+1];
        solve(i-1, up, down, maxnum, minnum);
    }

    else
    {

        int x = a[i]; int y = b[i];
        if(!up) y = 9;
        if(!down) x = 0;

        for(int k = x; k <= y; k++)
        {
            tmp[i] = k;
            solve(i-1, (up && tmp[i] == b[i]),
                       (down && tmp[i] == a[i]),
                       max(maxnum, tmp[i]), 
                       min(minnum, tmp[i]));
        }
    }
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> l >> r;

        if(l <= 9)
        {
            cout << min(9ll, r) << endl;
            continue;
        }

        cnt = 0;

        while(r)
        {
            a[++cnt] = l % 10;
            b[cnt] = r % 10;
            r /= 10;
            l /= 10;
        }

        
        ans = 20;

        solve(cnt, 1, 1, -10, 20);
        cout << num << endl;


        

    }

    

    return 0;
}