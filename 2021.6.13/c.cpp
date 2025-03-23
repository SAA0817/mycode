#include<iostream>
#include<algorithm>
#define MAXN 400005
#define LL long long
#define mod 1000000007
using namespace std;

int t;
int n;
int a[MAXN], b;
int f[MAXN];
int ans;

void init()
{
	for(int i = 1; i <= n; i++)
	    f[i] = i;
	ans = 1;
}

int getf(int num)
{
	if(f[num] == num) return num;
	f[num] = getf(f[num]);
	return f[num];
}

int main()
{
	cin >> t;
	
	for(int s = 1; s <= t; s++)
	{
		cin >> n;
		init();
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
		{
			cin >> b;
			
			if(getf(b) == a[i]) ans = (ans * 2) % mod;
			else f[a[i]] = b;
//			for(int j = 1; j <= n; j++)
//			    cout << getf(j) << " ";
//			cout << endl;
		}
		
			
		cout << ans << endl;
	}
	return 0;
} 
