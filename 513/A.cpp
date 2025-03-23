#include<cstdio>
#include<iostream>
#define MAXN 100005

using namespace std;

char c;
int n, l, a;
int s[MAXN], t[MAXN];
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
	n = read(); l = read(); a = read();
	int ans = 0;
	s[0] = 0; t[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		s[i] = read();
		t[i] = read();
		ans += (s[i] - (s[i-1] + t[i-1])) / a; 
	}
	ans += (l - s[n] - t[n]) / a ;
	cout << ans;
	return 0;
}
