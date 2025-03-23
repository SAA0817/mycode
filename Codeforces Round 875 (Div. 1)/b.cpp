#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;
using LL = long long;

const int MAXN = 2e5 + 5;

int t;
int n;

int mp[655][MAXN];

struct number{
	LL a, b;
}num[MAXN];

bool cmp(number x, number y)
{
	return x.a > y.a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while(t--)
	{
		LL ans = 0;

		cin >> n;

		for(int i = 1; i <= n; i++)
			cin >> num[i].a;

		for(int i = 1; i <= n; i++)
		{
			cin >> num[i].b;
			if(num[i].a <= 650)
			    mp[num[i].a][num[i].b]++;
		}

		

		sort(num+1, num+n+1, cmp);


		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 650; j++)
			{
				if(num[i].a * j - num[i].b > n) break;
				
				if(num[i].a * j - num[i].b <= 0)
					continue;

				ans += mp[j][num[i].a * j - num[i].b];

				if(num[i].a == j && num[i].b == num[i].a * j - num[i].b)
					ans--;
			}

			// cout << ans << " ";

			if(num[i].a <= 650)
			    mp[num[i].a][num[i].b]--;
		}
		cout << ans << endl;
	}
	


	return 0;
}