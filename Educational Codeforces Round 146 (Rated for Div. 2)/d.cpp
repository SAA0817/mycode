#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<vector>
#include<map>
#include<queue>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 3e3+5;

int t;
LL n, k;
LL ans;

struct gun{
    LL f, d;
}a[MAXN];

bool cmp(gun x, gun y)
{
    return x.f*x.d < y.f*y.d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        ans = n;
        for(int i = 1; i <= n; i++)
            cin >> a[i].f;
        for(int i = 1; i <= n; i++)
            cin >> a[i].d;

        sort(a+1, a+n+1, cmp);

        for(int i = 1; i <= n; i++)
        {
            int flag = 0;
            LL num = a[i].d * a[i].f;
            // cout << num << " ";

            for(int j = 1; j < i; j++)
            {
                LL tmp = ((num-1) / a[j].f) + 1;
                if(tmp * a[j].f - num > k)
                    num = (tmp-1) * a[j].f;
            }

            if(flag) continue;
            flag = 0;
            int tmpans = 0;

            for(int j = n; j >= i+1; j--)
            {
                if(a[j].f * a[j].d <= num + k)
                {
                    ans = min(n - j + i - 1, ans);
                    break;
                }
                else
                {
                    LL tmp = ((num-1) / a[j].f) + 1;
                    if(tmp * a[j].f - num > k)
                         num = (tmp-1) * a[j].f;
                }
            }
            // cout << ans << " ";
        }
        cout << ans << endl;

    }
    
    
    

    return 0;
}