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
int last = '0';
string a;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while(t--)
	{
		cin >> a;

		for(int i = 0; i < a.size(); i++)
			if(a[i] != '?')
			{
				last = a[i];
				break;
			}

		for(int i = 0; i < a.size(); i++)
		{
			if(a[i] == '?')
				a[i] = last;
			else
				last = a[i];
		}

		cout << a;
		cout << endl;

	}

	return 0;
}