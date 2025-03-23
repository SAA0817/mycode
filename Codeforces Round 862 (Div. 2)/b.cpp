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

const int MAXN = 1e5+5;

int t;
int n, m;

double a, b, c;
double ans;
int k[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            cin >> k[i];

        sort(k+1, k+n+1);

        for(int i = 1; i <= m; i++)
        {
            cin >> a >> b >> c;

            ans = c + ((b-k[1] * b-k[1]) / (4 * a));

            if((ans > 0 && a > 0) || (ans < 0 && a < 0))
            {
                cout << "YES" << endl;
                cout << k[1] << endl;
                continue;
            }

            ans = c + ((b-k[n] * b-k[n]) / (4 * a));

            if((ans > 0 && a > 0) || (ans < 0 && a < 0))
            {
                cout << "YES" << endl;
                cout << k[n] << endl;
                continue;
            }

            cout << "NO" << endl;

        }

    }

    

    return 0;
}