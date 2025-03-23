#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 4005;

int sum;

int n, m;
LL dp[MAXN][MAXN][2];
LL a[MAXN][15];

const int INF = 500000005;

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i][0];
        sum += a[i][0];
        for(int j = 1; j <= a[i][0]; j++)
        {
            cin >> a[i][j];
        }
    }

    m = min(sum, m);

    for(int j = 1; j <= m; j++)
    {
        dp[0][j][0] = -INF;
        dp[0][j][1] = -INF;
    }

    dp[0][0][1] = -INF;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {

            dp[i][j][0] = dp[i-1][j][0];
            dp[i][j][1] = dp[i-1][j][1];

            if(j >= a[i][0])
            {
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-a[i][0]][0] + a[i][a[i][0]]);
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-a[i][0]][1] + a[i][a[i][0]]);    
            }
        
            
            for(int k = 1; k <= a[i][0]; k++)
            {
                if(j >= k)
                {
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-k][0] + a[i][k]);
                }
            }
            // cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    } 
    
    cout << max(dp[n][m][0], dp[n][m][1]);


    return 0;
}