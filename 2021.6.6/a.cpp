#include<iostream>
#define MAXN 105

using namespace std;

int t;
int n;
int a[MAXN];

int main()
{
	cin >> t;
	
	for(int s = 1; s <= t; s++)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
		{
			if(a[i] < 0)
			{
				cout << "NO" << endl;
				break;
			}
			if(i == n)
			{
				cout << "YES" << endl;
				cout << 101 << endl;
				for(int j = 0; j <= 100; j++)
				    cout << j << " ";
				cout << endl;
			}
		}
		
	}
	return 0;
} 
