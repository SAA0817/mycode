#include<iostream>
#include<algorithm>
#define MAXN 5005
#define LL long long
using namespace std;


int n;
int map[MAXN];
int to[MAXN];
int ans;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	    scanf("%d", &map[i]);
	    
	for(int i = 1; i <= n; i++)
	{
		if(map[i] != 1) continue;
		int flag1 = 0, flag2 = 0;
		int l = -1, r = -1;
		
//		for(int j = 1; j <= n; j++)
//		    cout << map[j] << " ";
//		cout << endl;
		
		for(int j = i; j >= 1; j--)
		{
			if(!map[j])
			{
				l = j;
				break;
			}
			if(map[j] == 4)
			    flag1 = 2;
		}
			
			
		for(int j = i; j <= n; j++)
		{
			if(!map[j])
			{
				r = j;
				break;
			}
			if(map[j] == 3)
			    flag2 = 2;
		}
			
			
		if(l == -1)
		{
			map[r] = 2;//right
			map[i] = 4;
			to[i] = r;
			ans += (r - i - flag2);
			if(flag2)
			{
				int last = to[i];
				for(int j = r; j >= i; j--)
			        if(map[j] == 3)
			        {
			        	map[j] = 4;
			        	int t = to[j];
			        	to[j] = last;
			        	last = t;
			        }
			    to[i] = last;
			    if(last < i)
			        map[i] = 3;
			}
			    
			continue;
		}
		
		if(r == -1)
		{
			map[l] = 2;//left
			map[i] = 3;
			to[i] = l;
			ans += (i - l - flag1);
			if(flag1)
			{
				int last = to[i];
				for(int j = l; j <= i; j++)
			        if(map[j] == 4)
			        {
			        	map[j] = 3;
			        	int t = to[j];
			        	to[j] = last;
			        	last = t;
			        }
			    to[i] = last;
			    if(last > i)
			        map[i] = 4;
			}
			continue;
		}
		
		if((r - i - flag2) >= (i - l - flag1))
		{
			map[l] = 2;
			map[i] = 3;
			to[i] = l;
			ans += (i - l - flag1);
			if(flag1)
			{
				int last = to[i];
				for(int j = l; j <= i; j++)
			        if(map[j] == 4)
			        {
			        	map[j] = 3;
			        	int t = to[j];
			        	to[j] = last;
			        	last = t;
			        }
			    to[i] = last;
			    if(last > i)
			        map[i] = 4;
			}
		}
		else
		{
			map[r] = 2;
			map[i] = 4;
			to[i] = r;
			ans += (r - i - flag2);
			if(flag2)
			{
				int last = to[i];
				for(int j = r; j >= i; j--)
			        if(map[j] == 3)
			        {
			        	map[j] = 4;
			        	int t = to[j];
			        	to[j] = last;
			        	last = t;
			        }
			    to[i] = last;
			    if(last < i)
			        map[i] = 3;
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}
