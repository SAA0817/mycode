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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        a[1] = 2e9;
        for(int i = 1; i <= n-1; i++)
        {
            cin >> b[i];
            if(a[i] > b[i]) a[i] = b[i];
            a[i+1] = b[i];
        }
        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
        

    }
    
    
    

    return 0;
}