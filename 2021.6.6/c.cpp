#include<iostream>
#include<algorithm>
#define MAXN 500005

using namespace std;

int t, n;
int a[MAXN];
int ans[MAXN];
int tmp[MAXN];
bool vis[MAXN];

int main()
{
	cin >> t;
	
	for(int s = 1; s <= t; s++)
	{
		cin >> n;
		char c;
		for(int i = 1; i <= n; i++)
		{
			while(c != 'D' && c != 'K') c = getchar();
			if(c == 'D') a[i] = a[i-1] + 1;
			else a[i] = a[i-1];
			c = getchar();
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			    vis[j] = 0;
			int cnt = 0;
			tmp[++cnt] = 1;
			for(int j = 2; j <= i; j++)
			{
				if(vis[j]) continue;
				if(i % j == 0)
				{
					for(int k = j; k < i; k += j)
						vis[k] = 1;
					tmp[++cnt] = j;
				}
			}
			sort(tmp+1, tmp+cnt+1);
			ans[i] = 0;
			for(int j = 1; j <= cnt; j++)
			{
				//cout << tmp[j] << " ";
				if(ans[i-tmp[j]] == (i/tmp[j])-1 && (a[i] * (i-tmp[j])) == (a[i-tmp[j]] * i))
				{
					ans[i] = (i/tmp[j]);
					break;
				}
			}
			//cout << endl;
			if(!ans[i]) ans[i] = 1;
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
} 
