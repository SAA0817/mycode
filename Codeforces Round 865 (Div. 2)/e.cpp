#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#define LL long long 

using namespace std;


const int MAXN = 1505;

int t;
int n, m;

bool vis[MAXN];




int cnt[MAXN];
int id[MAXN];
bool fa[MAXN][MAXN];

bool cmp(int x, int y)
{
    if(cnt[x] == cnt[y]) return x < y;
    return cnt[x] > cnt[y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        bool flag = 0;
        vector<int> e[MAXN];
        queue<int> q;
        int x, y;
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            fa[y][x] = 1;
            e[y].push_back(x);
        }

        for(int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            cnt[i] = -1;
            id[i] = i;
        }

        cnt[1] = 1;
        vis[1] = 1;
        q.push(1);

        while(!q.empty())
        {
            int num = q.front();
            q.pop();
            vis[num] = 1;

            // cout << num << endl;

            // for(auto i:e[num])
            //     if(cnt[i] < cnt[num] && cnt[i] != -1 && i != 1)
            //         cnt[num] = cnt[i];
            for(auto i:e[num])
            {
                if(!vis[i])
                {
                    // if(fa[i][num] && num != 1)
                    // {
                    //     // cout << num << " " << i;
                    //     cnt[i] = cnt[num];
                    // }
                    // else
                        cnt[i] = cnt[num]+1;
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }

        LL ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(cnt[i] == -1)
            {
                flag = 1;
                break;
            }
            ans += cnt[i];
        }

        if(flag)
        {
            cout << "INFINITE" << endl;
            for(int i = 1; i <= n; i++)
                for(auto j:e[i])
                {
                    fa[i][j] = 0;
                    fa[j][i] = 0;
                }
            continue;
        }

        cout << "FINITE" << endl;

        sort(id+1, id+n+1, cmp);

        cout << ans << endl;

        for(int i = 1; i <= cnt[id[1]]; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(cnt[id[j]] < i) break;
                cout << id[j] << " ";
            }
        }
        cout << endl;

        for(int i = 1; i <= n; i++)
            for(auto j:e[i])
            {
                fa[i][j] = 0;
                fa[j][i] = 0;
            }



        

    }

    
    return 0;
}
