#include<iostream>
#define MAXN 1005

using namespace std;

int t, n;
char a[MAXN];
char cmp[MAXN<<1][3];
char c[3];


void getch(int num)
{
	if(num <= 26)
	{
		c[2] = char('a' + num - 1);
	}
	else if(num <= 26*27)
	{
		num--;
		c[1] = char('a' + (num / 26) - 1);
		num %= 26;
		num++;
		c[2] = char('a' + num - 1);
	}
	else
	{
		c[0] = 'a';
		num -= 26 * 26;
		num--;
		c[1] = char('a' + (num / 26) - 1);
		num %= 26;
		num++;
		c[2] = char('a' + num - 1);
	}
}

int main()
{
	
	cin >> t;
	
	for(int s = 1; s <= t; s++)
	{
		cin >> n;
		cin >> a;
		bool flag = 1;
		int cnt = 0;
		while(flag)
		{
			bool last1 = 0, last2 = 0;
			getch(++cnt);
			flag = 0;
			for(int i = 0; i < n; i++)
			{
				if(cnt <= 26 && a[i] == c[2])
				{
					flag = 1;
					break;
				}
				if(cnt <= 26*27 && cnt > 26)
				{
					if(last1 && a[i] == c[2])
					{
					flag = 1;
					break;
					}
					if(a[i] == c[1]) last1 = 1;
					else last1 = 0;
				} 
				if(cnt > 26*27)
				{
					if(last2 && a[i] == c[2])
					{
						flag = 1;
						break;
					}
					if(last1 && a[i] == c[1]) last2 = 1;
					else last2 = 0;
					if(a[i] == c[0]) last1 = 1;
					else last1 = 0;
				}
				
			}
		}
		if(cnt <= 26) cout << c[2] << endl;
		else if(cnt <= 26*27) cout << c[1] << c[2] << endl;
		else cout << c[0] << c[1] << c[2] << endl;
		
	}
	return 0;
} 
