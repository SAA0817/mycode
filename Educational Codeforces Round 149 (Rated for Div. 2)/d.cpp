#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;
using LL = long long;

const int MAXN = 3e5 + 5;

int t;
int n, k;
char a[MAXN];
int v[MAXN];
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while(t--)
	{
		int ans = 0;

		cin >> n;
		cin >> a+1;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == '(') 
				v[i] = v[i-1] + 1;
			else 
			    v[i] = v[i-1] - 1;

			if(v[i] < 0) ans |= 2;
			if(v[i] > 0) ans |= 1;
		}

		if(v[n] != 0)
		{
			cout << -1 << endl;
			continue;
		}



		int tmp = 0;
		if(ans == 2) tmp = -1;

		if(ans >= 2) ans--;
		cout << ans << endl;
		for(int i = 1; i <= n; i++)
		{
			if(v[i] == 0) v[i] = v[i-1];

			if(v[i] < 0) cout << 2 + tmp << " ";
			else cout << 1 << " ";
		}
		cout << endl;
	}

	return 0;
}