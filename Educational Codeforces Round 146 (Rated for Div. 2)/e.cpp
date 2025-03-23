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

int n;
LL a[MAXN];
LL dp[MAXN][2];
LL dp2[MAXN][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n-1; i++)
        cin >> a[i];

    dp[1][0] = a[1];
    dp[1][1] = a[1];

    for(int i = 2; i <= n-1; i++)
    {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i];
        dp[i][1] = dp[i-1][0];
    }

    dp2[n-1][0] = a[n-1];
    dp2[n-1][1] = a[n-1];

    for(int i = n-2; i >= 1; i--)
    {
        dp2[i][0] = min(dp2[i+1][0], dp2[i+1][1]) + a[i];
        dp2[i][1] = dp2[i+1][0];
    }

    int q;
    cin >> q;
    while(q--)
    {
        LL k, x;
        cin >> k >> x;
        LL ans = dp[k-1][1] + x + dp2[k+1][1];
        
        ans = min(ans, dp[k-1][0] + dp2[k+1][0]);
        ans = min(ans, dp[k-1][0] + dp2[k+1][1] + x);
        ans = min(ans, dp[k-1][1] + dp2[k+1][0] + x);
        cout << ans * 2 << endl;
    }
    

    return 0;
}