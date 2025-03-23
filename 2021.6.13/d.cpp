#include<bits/stdc++.h>
#define MAXN 2005

using namespace std;

int n;
int anscnt;
int ans[MAXN][2];
int d[MAXN];
bool vis[MAXN];

stack<int> toask;

int main()
{
	
	cin >> n;
	cout << "? " << 1 << endl;
	vis[1] = 1;
	fflush(stdout);
	for(int i = 1; i <= n; i++)
		cin >> d[i];
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; i++)
	{
		if(d[i] % 2 == 1) cnt1++;
		else cnt2++;
	}
	if(cnt2 > cnt1)
	{
		vis[1] = 0;
		for(int i = 2; i <= n; i++)
			if(d[i] % 2 == 1 && toask.empty()) toask.push(i);
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			if(d[i] == 2)
			{
				toask.push(i);
				vis[i] = 1;
			}
			if(d[i] == 1)
			{
				anscnt++;
				ans[anscnt][0] = 1;
				ans[anscnt][1] = i;
			}
		}
	}
	
	while(anscnt < n-1)
	{
		int num = toask.top();
		toask.pop();
		cout << "? " << num << endl;
		vis[num] = 1;
		
		fflush(stdout);
		for(int i = 1; i <= n; i++)
		    cin >> d[i];
		for(int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			if(d[i] == 2)
			{
				toask.push(i);
				vis[i] = 1;
			}
			if(d[i] == 1)
			{
				anscnt++;
				ans[anscnt][0] = num;
				ans[anscnt][1] = i;
			}
		}
		
	}
	cout << "!" << endl;
	for(int i = 1; i <= anscnt; i++)
		cout << ans[i][0] << " " << ans[i][1] << endl;
	fflush(stdout);
	return 0;
} 
