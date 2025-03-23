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

const int MAXN = 1e5+5;

int t;
int n, m;
int d[MAXN];
int d2[MAXN];
int maxd;
int tmp;
int cnt[MAXN];
int ans[MAXN];

vector<int> e[MAXN];

void dfs(int num, int fa)
{
    for(auto i : e[num])
    {
        if(i == fa) continue;
        d[i] = d[num] + 1;
        maxd = max(maxd, d[i]);
        if(d[i] == maxd) tmp = i;
        dfs(i, num);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    d[1] = 1;

    dfs(1, -1);

    maxd = 0;
    d[tmp] = 0;

    dfs(tmp, -1);

    for(int i = 1; i <= n; i++)
        d2[i] = d[i];

    d[tmp] = 0;
    
    dfs(tmp, -1);

    for(int i = 1; i <= n; i++)
    {
        d2[i] = max(d2[i], d[i]);
        // cout << d2[i] << " ";
    }

    // cout << endl;


    

    ans[n+1] = n;

    for(int i = 1; i <= n; i++)
    {
        cnt[d2[i]]++;
    }
    
    bool flag = 1;
    ans[maxd]++;

    for(int i = n; i >= 1; i--)
    {
        ans[i] += ans[i+1];
        ans[i] -= cnt[i];
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    

    return 0;
}