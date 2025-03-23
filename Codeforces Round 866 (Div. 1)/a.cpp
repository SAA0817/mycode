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
int vis[MAXN];
int m;

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
        {
            cin >> a[i];
            if(a[i] <= 200000)
            {
                vis[a[i]]++;
            }
        }

        for(int i = 0; i <= n+1; i++)
            if(!vis[i])
            {
                m = i;
                break;
            }

        int l, r;
        l = -1;

        for(int i = 1; i <= n; i++)
        {
            if(a[i] == m+1)
            {
                l = i;
                break;
            }
        }

        for(int i = n; i >= 1; i--)
        {
            if(a[i] == m+1)
            {
                r = i;
                break;
            }
        }

        if(m == n)
            cout << "no" << endl;
        else if(l == -1)
            cout << "yes" << endl;
        else
        {
            for(int i = l; i <= r; i++)
            {
                if(a[i] > 200000)
                    continue;
                vis[a[i]]--;
                if(vis[a[i]] == 0 && a[i] < m)
                {
                    cout << "no" << endl;
                    break;
                } 
                if(i == r)
                    cout << "yes" << endl;
            }
        }


        for(int i = 1; i <= n; i++)
        {
            if(a[i] <= 200000)
                vis[a[i]] = 0;
        }



        
    }

    
    return 0;
}