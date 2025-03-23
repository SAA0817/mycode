#include<iostream>
#define MAXN 55

using namespace std;

int t;
int n, m;
char a[MAXN][MAXN];
char c;
int cnt;
bool flag1, flag2;

void init()
{
	
	flag1 = 0; flag2 = 0;
}

int main()
{
	cin >> t;
	
	for(int s = 1; s <= t; s++)
	{
		init();
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			while(c != '.' && c != 'W' && c != 'R')
			    c = getchar();
			cnt = 0;
			while(c == '.' || c == 'W' || c == 'R')
			{
			    a[i][++cnt] = c;
				c = getchar();
			}
			
		}
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(a[i][j] == 'W')
				{
					if((i+j)%2) flag1 = 1;
					else flag2 = 1;
				}
				if(a[i][j] == 'R')
				{
					if((i+j)%2) flag2 = 1;
					else flag1 = 1;
				}
			}
		}
		if(flag1 && flag2)
		{
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		if(flag1)
		{
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= m; j++)
			    {
			    	if((i+j)%2)
			    	    cout << 'W';
			    	else
			    	    cout << 'R';
			    }
			    cout << endl;
			}
			continue;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
		    {
		    	if((i+j)%2)
		    	    cout << 'R';
		    	else
		    	    cout << 'W';
		    }
		    cout << endl;
		}
	}
	return 0;
} 
