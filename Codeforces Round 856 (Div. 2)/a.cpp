#include<iostream>
#include<cstring>

#include<algorithm>

using namespace std;


int t;
int n;
char a[50][50];
char x, y;

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--)
	{
		memset(a, 0, sizeof(a));
		x = 0; y = 0;

		cin >> n;

		for(int i = 1; i <= n*2-2; i++)
		{
			cin >> a[i]+1;
			if(a[i][n/2] && !a[i][n/2+1])
			{
				if(!x) x = i;
				else y = i;
			} 

		}

		for(int i = 1; i <= n/2; i++)
		{
			if(a[x][i] != a[y][n/2-i+1])
			{

				cout << "NO" << endl;
				break;
			}
			if(i == n/2) cout << "YES" << endl;
		}

	}


	return 0;
}