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

const int MAXN = 1005;
const int mod = 1e9+7;

int t;
int n;

int a[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        int ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ans ^= a[i];
        }
        if(n % 2 == 1) cout << ans << endl;
        else cout << (ans ? -1 : 0) << endl;
    }

    

    return 0;
}