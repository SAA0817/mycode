#include<cstdio>
#include<iostream>
#define LL long long

using namespace std;

int t;
LL num, ans;
char c;
LL read()
{
	c = getchar();
	LL res = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9')
	{
		res *= 10;
		res += c - '0';
		c = getchar();
	}
	return res; 
}


int main()
{
	cin >> t;
	while(t--)
	{
		num = read();
		ans = 1;
		while(num)
		{
			if(num % 2 == 1)
			    ans *= 2;
			num = num >> 1;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
