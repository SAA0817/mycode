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

struct Node{
    int id;
    LL x, y;
}a[MAXN], l[MAXN], r[MAXN];

int t;
int n;
int cnt;
LL sum;
LL maxx, maxy;
LL sl, sr;

LL ans[3][3];

bool vis[MAXN];

bool cmpl(Node a, Node b)
{
    if(a.x == b.x) return a.y > b.y;
    return a.x > b.x;
}

bool cmpr(Node a, Node b)
{
    if(a.y == b.y) return a.x > b.x;
    return a.y > b.y;
}

void init()
{
    sl = 1; sr = 1;
    for(int i = 1; i <= n+1; i++)
        vis[i] = 0;
}

bool solve(int x, int y)
{
    // cout << x << " " << y << endl;
    //if(x < 0 || y < 0) return false;
    if(x == 0 || y == 0) return true;

    while(vis[l[sl].id]) sl++;

    while(vis[r[sr].id]) sr++;

    if(x == l[sl].x)
    {
        vis[l[sl].id] = 1;
        sl++;
        return solve(x, y-l[sl-1].y);
    }

    else if(y == r[sr].y)
    {
        vis[r[sr].id] = 1;
        sr++;
        return solve(x-r[sr-1].x, y);
    }

    else
        return false;
    

}


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

        maxx = 0; maxy = 0;
        sum = 0;

        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y;
            maxx = max(maxx, a[i].x);
            maxy = max(maxy, a[i].y);
            sum += a[i].x * a[i].y;
            a[i].id = i;
            l[i] = a[i];
            r[i] = a[i];
        }

        sort(l+1, l+n+1, cmpl);
        sort(r+1, r+n+1, cmpr);

        init();

        if(solve(sum/maxy, maxy) && (sum % maxy) == 0)
        {
            ans[++cnt][0] = sum/maxy;
            ans[cnt][1] = maxy;
        }

        init();

        if(solve(maxx, sum/maxx) && (sum % maxx) == 0 && maxx * maxy != sum)
        {
            ans[++cnt][0] = maxx;
            ans[cnt][1] = sum/maxx;
        }

        cout << cnt << endl;
        for(int i = 1; i <= cnt; i++)
            cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    
    return 0;
}