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
int q;
LL a, b, n;
LL maxh, minh;
LL l, r;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> q;

        l = 0;
        r = 2e18;
        
        while(q--)
        {
            int k;
            cin >> k;
            if(k == 1)
            {
                cin >> a >> b >> n;
                maxh = (a-b) * (n-1) + a;
                if(n != 1) minh = (a-b) * (n-2) + a + 1;
                else minh = 0;

                if(maxh < l || minh > r) cout << 0 << " ";
                else
                {
                    cout << 1 << " ";
                    l = max(minh, l);
                    r = min(maxh, r);
                }
                // cout << "(" << l << " " << r << ")";
            } 
            else
            {
                cin >> a >> b;
                LL ans1 = 1 + max(0ll, ((r-a)+(a-b)-1) / (a - b));
                LL ans2 = 1 + max(0ll, ((l-a)+(a-b)-1) / (a - b));
                if(ans1 != ans2) cout << -1 << " ";
                else cout << ans1 << " ";
            }

        }

        cout << endl;
        

    }

    

    return 0;
}