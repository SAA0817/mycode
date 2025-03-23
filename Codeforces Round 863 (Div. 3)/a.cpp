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
char a[MAXN];
int n, d;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        bool flag = 0;
        cin >> n >> d;
        cin >> a;
        for(int i = 0; i < n; i++)
        {
            if(a[i] < d + '0' && !flag)
            {
                flag = 1;
                cout << d;
            }
            cout << a[i];
        }
        if(!flag) cout << d;
        cout << endl;

    }
    
    
    

    return 0;
}