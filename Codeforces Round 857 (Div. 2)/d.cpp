#include<iostream>
#include<algorithm>
#include<bitset>
#define endl '\n'
using namespace std;

int T;
int n, m;

const int MAXN = 5e5 + 5;

int a[MAXN], b[MAXN];
int i, j;
int vis[MAXN];
int ans;

struct node{
    int a, b;
}s[MAXN], s2[MAXN];

bool cmp(node x, node y)
{
    return x.a < y.a;
}

bool cmp2(node x, node y)
{
    return x.b < y.b;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;

    while(T--)
    {
        
        cin >> n;

        a[n+1] = -1;
        b[n+1] = -1;
        
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
            s[i].a = a[i];
            s[i].b = b[i];
        }
        
        sort(a+1, a+n+1);
        sort(b+1, b+n+1);
        sort(s+1, s+n+1, cmp);
        sort(s2+1, s2+n+1, cmp2);

        ans = 1e9+10;
        int cnt = 1;
        int maxb = 0;
        int maxa = 0;

        for(int i = 1; i <= n; i++)
        {
            ans = min(ans, a[i] - maxb);
            maxb = max(maxb, s[i].b);
            if(maxb > a[i]) break;
        }

        for(int i = 1; i <= n; i++)
        {
            ans = min(ans, b[i] - maxa);
            maxa = max(maxb, s2[i].a);
            if(maxa > b[i]) break;
        }

        cout << ans << endl;


        
    }


    return 0;
}