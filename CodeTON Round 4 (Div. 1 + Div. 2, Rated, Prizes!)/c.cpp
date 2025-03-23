#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<vector>
#include<map>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 1e5 + 5;
const int mod = 1e9+7;

int t;
LL n;
LL c, d;
LL a[MAXN], b[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> c >> d;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(b+1, b+n+1);



        int cnt = 0;
        LL num = 0;

        for(int i = 1; i <= n; i++)
        {
            if(b[i] != b[i-1])
                a[++cnt] = b[i];
            else
                num++;
        }

        n -= num;
        num *= c;


        LL ans = (c * n) + d;

        // cout << a[1] << endl;

        for(int i = 1; i <= n; i++)
        {
            ans = min(ans, (a[i] - i) * d + (n - i) * c);
            // cout << ans << endl;
        }
        // cout << "!!!";
        cout << ans + num << endl;

    }

    

    return 0;
}