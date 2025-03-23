#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 5;

int t;
int d[MAXN];
int dp[MAXN];
int n;
int ans;
int cnt;

struct Edge{
	int v;
	int w;
	Edge *next;
}pool[MAXN * 2], *h[MAXN];

void addEdge(int x, int y, int w)
{
	Edge *p = &pool[++cnt];
	p->v = y;
	p->w = w;
	p->next = h[x];
	h[x] = p;
}

void dfs(int x, int fa)
{
	for(Edge *p = h[x]; p; p = p->next)
	{
		if(p->v == fa) continue;

		dp[p->v] = p->w;

		d[p->v] = d[x];
		if(p->w < dp[x])
			d[p->v]++;

		ans = max(ans, d[p->v]);

		dfs(p->v, x);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	
	while(t--)
	{
		cin >> n;

		ans = 0;
		cnt = 0;
		for(int i = 1; i <= n; i++)
			h[i] = NULL;


		for(int i = 1; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			addEdge(x, y, i);
			addEdge(y, x, i);
		}

		dfs(1, -1);
		cout << ans+1 << endl;

	}



	return 0;
}