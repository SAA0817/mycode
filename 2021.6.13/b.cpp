#include<iostream>
#include<algorithm>
#define MAXN 400005
#define LL long long

using namespace std;

int t;
int n;
int num;
int last;
int a[MAXN];
LL ans;

void init()
{
	a[n+1] = 0;
	ans = 0;
}

int main()
{
	cin >> t;
	
	for(int s = 1; s <= t; s++)
	{
		cin >> n;
		init();
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			ans += max(a[i]-a[i-1], a[i-1]-a[i]);
		}
		ans += a[n];
			
		for(int i = 1; i <= n; i++)
		{
			if(a[i] > a[i-1] && a[i] > a[i+1])
			    ans -= min(a[i] - a[i-1], a[i] - a[i+1]);
		}
		cout << ans << endl;
	}
	return 0;
} 
