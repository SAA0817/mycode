#include<cstdio>
#include<iostream>

using namespace std;

int t;
char c;
int s, a, b, d;
long long ans;
int read()
{
	c = getchar();
	int res = 0;
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
	t = read();
	while(t--)
	{
		s = read();
		a = read();
		b = read();
		d = read();
		ans = s / d;
		ans += (ans/a) * b;
		printf("%I64d\n", ans);
	}
	return 0;
}
