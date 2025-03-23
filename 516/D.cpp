#include<cstdio>
#include<iostream>
#define MAXN 2005

using namespace std;

bool map[MAXN][MAXN], vis[MAXN][MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN];
int ans;
int n, m;
int ln, rn;
char c;
void dfs(int x, int y)
{
	
	if(!vis[x][y])
	    ans++;
	vis[x][y] = 1;
	if(vis[x][y] && l[x][y] >= ln && r[x][y] >= rn)
	    return;
	l[x][y] = max(l[x][y], ln);
	r[x][y] = max(r[x][y], rn);
		//cout << x << " " << y << endl;
	if(x > 1 && !map[x-1][y]) dfs(x-1, y);
	if(x < n && !map[x+1][y]) dfs(x+1, y);
	if(y > 1 && !map[x][y-1] && ln)
	{
		ln--;
		dfs(x, y-1);
		ln++;
	}
	if(y < m && !map[x][y+1] && rn)
	{
		rn--;
		dfs(x, y+1);
		rn++;
	}
	
}

int main()
{
	int x, y;
	scanf("%d %d\n", &n, &m);
	scanf("%d %d\n", &x, &y);
	scanf("%d %d", &ln, &rn);
	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= m; j++)
	    {
	    	c = getchar();
			while(c != '*' && c != '.')c = getchar();
	    	if(c == '*')
	    	    map[i][j] = 1;
		}
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 1; j <= m; j++)
//		    cout << vis[i][j];
//		cout << endl;
//	}
//	    
	dfs(x, y);
	cout << ans;
}
