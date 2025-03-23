#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<vector>
#include<map>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 4005;
const int mod = 1e9+7;

int t;
int n;
int ans[MAXN];
bool flag;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        if(n % 2 == 0)
        {
            cout << -1 << endl;
            continue;
        }

        int cnt = 0;

        while(n > 1)
        {
            n /= 2;
            if(n % 2 == 0)
            {
                ans[++cnt] = 1;
                n++;
            }
            else
                ans[++cnt] = 2;
        }

        cout << cnt << endl;
        for(int i = cnt; i >= 1; i--)
            cout << ans[i] << " ";
        cout << endl;

    }

    

    return 0;
}