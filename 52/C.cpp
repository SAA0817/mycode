#include<cstdio>
#include<iostream>
#define LL long long
#define MAXN 200005
#define mid (l + r) / 2

using namespace std;

char c;
int n, k;
int h[MAXN];
int top, low = 2000000000;

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

int solve(int l, int r)
{
	//cout << l << " " << r << endl;
	LL ans = 0;
	if(l == r)
	{
		for(int i = 1; i <= n; i++)
		    if(h[i] > (top - mid))
		        ans += h[i] - (top - mid);
		if(ans > k) return mid - 1;
		else return mid;
	}
	for(int i = 1; i <= n; i++)
	    if(h[i] > (top - mid))
	        ans += h[i] - (top - mid);
	if(ans == k)
		return mid;
	if(ans > k) return solve(l, mid);
	if(ans < k) return solve(mid + 1, r);
}

int main()
{
	n = read(); k = read();
	for(int i = 1; i <= n; i++)
	{
		h[i] = read();
		top = max(top, h[i]);
		low = min(low, h[i]);
	}
	int cnt = 0;
	while(top > low)
	{
		int s = solve(0, top);
		for(int i = 1; i <= n; i++)
		    if(top - h[i] < s)
		        h[i] = top - s;
		top -= s;
		cnt++;
	}
	cout << cnt;
	return 0;
}
