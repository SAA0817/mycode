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

const int MAXN = 3e5+5;

int t;
int n;
LL a[MAXN];
int ans;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;

        for(int i = 1; i <= n; i++)
            cin >> a[i];

        if(n % 2 == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        
        for(int i = 2; i < n; i++)
        {
            a[i+1] -= a[i] - a[i-1];
            a[i] -= a[i] - a[i-1];
        }
        if(a[n] >= a[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }

    
    return 0;
}