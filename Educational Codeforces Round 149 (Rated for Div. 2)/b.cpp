#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;
using LL = long long;

const int MAXN = 2e5 + 5;

int t;
int n, k;
char a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while(t--)
	{
		int ans = 0;
		int tmp = 0;

		cin >> n;
		cin >> a;

		for(int i = 1; i < n; i++)
		{
			if(a[i] == a[i-1]) tmp++;
			else tmp = 0;
			ans = max(ans, abs(tmp));
		}

		cout << ans+2 << endl;

	}

	return 0;
}