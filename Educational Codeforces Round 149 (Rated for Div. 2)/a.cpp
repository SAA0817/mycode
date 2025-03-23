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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		if(n % k == 0)
		{
			cout << 2 << endl;
			cout << k-1 << " " << n-k+1 << endl;
		}
		else
		{
			cout << 1 << endl << n << endl;
		}
	}


	return 0;
}