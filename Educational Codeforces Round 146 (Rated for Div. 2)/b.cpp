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

const int MAXN = 2e5+5;

int t;
int n;
int s1, s2;
int r[MAXN];
int ans[MAXN][2];

struct num{
    int id;
    int v;
}a[MAXN];

bool cmp(num x, num y)
{
    return x.v > y.v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s1 >> s2;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].v;
            a[i].id = i;
        }

        sort(r+1, r+n+1, cmp);

        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 1; i <= n; i++)
        {
            if((cnt1+1) * s1 >= (cnt2+1) * s2) ans[++cnt1][0] = a[i].id;
            else ans[++cnt2][1] = a[i].id;
        }

        cout << cnt1;
        for(int i = 1; i <= cnt1; i++)
            cout << ans[i][0] << " ";
        cout << endl;

        cout << cnt2;
        for(int i = 1; i <= cnt2; i++)
            cout << ans[i][1] << " ";
        cout << endl;


    }
    
    
    

    return 0;
}