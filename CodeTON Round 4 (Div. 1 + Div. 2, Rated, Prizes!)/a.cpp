#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<vector>
#include<map>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 405;
const int mod = 1e9+7;

int t;
int n;
int a[MAXN];
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

        flag = 0;
        
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(a[i] <= i) flag = 1;
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }

    

    return 0;
}