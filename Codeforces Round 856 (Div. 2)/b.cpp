#include<iostream>
#include<cstring>

#include<algorithm>

using namespace std;

const int MAXN = 1e4+5;

int t;
int n;
int a[MAXN];
char x, y;

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(a[i] == 1) a[i]++;
		}
		for(int i = 1; i < n; i++)
		{
			if(a[i+1]%a[i] == 0) a[i+1]++;
		}
		for(int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;

	}


	return 0;
}