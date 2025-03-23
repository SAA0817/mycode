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
int a[MAXN];
int b[MAXN];
LL f[45];
int x, y;
LL x1, x2, y1, y2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    f[0] = 1;
    f[1] = 1;

    for(int i = 2; i <= 44; i++)
        f[i] = f[i-1] + f[i-2];

    while(t--)
    {
        cin >> n >> x >> y;
        x1 = 1; y1 = 1;
        for(int i = n; i >= 1; i--)
        {
            if((n-i) % 2 == 1)
            {
                if(x1 + f[i] <= x) x1 += f[i];
            }
            else
            {
                if(y1 + f[i] <= y) y1 += f[i];
            }
            // cout << f[i] << " ";
            // cout << x1 << " " << y1 << endl;
        }
        
        if(x1 == x && y1 == y)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;


    }
    
    
    

    return 0;
}