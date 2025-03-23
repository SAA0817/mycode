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

int find(int l, int r)
{
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(k[mid] < b) return find(mid+1, r);
    else return find(l, mid);
}

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

            int num = find(1, n);

            ans = c - ((b-k[num]) / (4 * a) * (b-k[num]));

            if(ans > 0)
            {
                cout << "YES" << endl;
                // cout << ans << endl;
                cout << k[num] << endl;
                continue;
            }

            if(num != 1) ans = c - ((b-k[num-1]) / (4 * a) * (b-k[num-1]));

            if(ans > 0)
            {
                cout << "YES" << endl;
                // cout << ans << endl;
                cout << k[num-1] << endl;
                continue;
            }

            if(num != n) ans = c - ((b-k[num+1]) / (4 * a) * (b-k[num+1]));

            if(ans > 0)
            {
                cout << "YES" << endl;
                // cout << ans << endl;
                cout << k[num+1] << endl;
                continue;
            }


            cout << "NO" << endl;

        }

    }

    

    return 0;
}