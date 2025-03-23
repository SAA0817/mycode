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
int cnt;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt = 0;
        for(int i = 1; i <= n/2; i++)
        {
            cout << (n-i+1) * 2 << " ";
            a[++cnt] = (n-i+1) * 2;
            if((n-i+1) != i)
            {
                a[++cnt] = i*2;
                cout << i * 2 << " ";
            }
        }
        cout << endl;

        for(int i = 2; i <= n; i++)
            cout << a[i]-1 << " ";
        cout << n*2-1 << endl;
    }

    
    return 0;
}