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

const int MAXN = 2e5 + 5;
const int mod = 1e9+7;

int t;
LL n, m;
bool vis[MAXN];
bool vis2[MAXN];
vector<int> e[MAXN];

struct Node{
    int v;
}a[MAXN];

struct cmp {
    bool operator()(const int &x, const int &y) {
        return a[x].v > a[y].v;
    }
};

bool solve(int num)
{

    priority_queue<int, vector<int>, cmp> q;
    queue<int> clear;
    
    q.push(num);
    clear.push(num);

    vis2[num] = 1;

    int cnt = 0;

    while(!q.empty())
    {
        int tmp = q.top();
        q.pop();

        if(a[tmp].v > cnt)
        {
            while(!clear.empty())
            {
                vis2[clear.front()] = 0;
                clear.pop();
            }
            return false;
        }

        vis[tmp] = 1;

        for(auto i : e[tmp])
        {
            if(!vis2[i])
            {
                clear.push(i);
                q.push(i);
                vis2[i] = 1;
            }
        }

        cnt++;
    }
    while(!clear.empty())
    {
        vis2[clear.front()] = 0;
        clear.pop();
    }
    if(cnt == n) return true;
    else return false;

    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--) //init()
    {
        

        cin >> n >> m;
        // for(int i = 1; i <= n; i++)
        //     cout << vis2[i];
        // cout << endl;
        for(int i = 1; i <= n; i++)
            cin >> a[i].v;
        for(int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        for(int i = 1; i <= n; i++)
        {
            if(!vis[i] && a[i].v == 0)
                if(solve(i))
                {
                    cout << "YES" << endl;
                    break;
                }
            if(i == n)
                cout << "NO" << endl;

        }

        for(int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            e[i].clear();
        }


    }

    

    return 0;
}