#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<vector>
#include<map>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 3e5 + 5;
const int mod = 1e9 + 7;

int t;
int n, m;
int l, r;
int num;

LL ans;

vector<LL> a[MAXN];
int tmp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        ans = 0;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                cin >> tmp;
                a[j].push_back(tmp);
            }

        for(int i = 1; i <= m; i++)
            sort(a[i].begin(), a[i].end());

        for(int i = 1; i <= m; i++)
        {
            LL sum = a[i][0];
            for(int j = 1; j < n; j++)
            {
                ans += a[i][j] * j - sum;
                sum += a[i][j];
        
                // cout << a[i][j] << " ";
            }
            // cout << endl;
        }

        cout << ans << endl;

        for(int i = 1; i <= m; i++)
            a[i].clear();
        
    }

    

    return 0;
}