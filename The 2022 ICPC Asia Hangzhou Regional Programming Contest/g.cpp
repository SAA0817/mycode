#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 1e5+5;

int t;
int n, m;
int d[MAXN];
int e[MAXN][2];
int f[2];

void init()
{
    for(int i = 1; i <= n; i++)
        d[i] = 0;
    
    f[0] = 0;
    f[1] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        init();

        for(int i = 1; i <= m; i++)
        {
            cin >> e[i][0] >> e[i][1];
            d[e[i][0]]++;
            d[e[i][1]]++;
        }

 		if(m == n-1) 
		{
			cout << "YES" << endl;
			continue;
		}

        for(int i = 1; i <= m; i++)
        {
            if(d[e[i][0]] == 1 || d[e[i][1]] == 1)
                continue;

            if(!f[0])
            {
                f[0] = d[e[i][0]];
                f[1] = d[e[i][1]];    
            }

            else if(f[0] == d[e[i][0]] && f[1] == d[e[i][1]] || f[0] == d[e[i][1]] && f[1] == d[e[i][0]])
                continue;

            else
            {
                cout << "NO" << endl;
                goto end;
            }
            
        }

        cout << "YES" << endl;
        end:;
        
    }

    return 0;
}