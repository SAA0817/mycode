#include<cstdio>
#include<iostream>
#define MAXN 200005
#define LL long long

using namespace std;

char c;
int n, k, h;
int top, low;
int b[MAXN];
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
	n = read(); k = read();
	for(int i = 1; i <= n; i++)
	{
		h = read();
		top = max(top, h);
		if(i == 1) low = h;
		low = min(low, h);
		b[h]++;
	}
	int ans = 0;
	int cnt = 0;
	int num = 0;
	for(int i = top; i > low; i--)
	{
		cnt += b[i];
		if(num + cnt > k)
		{
			num = cnt;
			ans++;
		}
		else
			num += cnt;  
	//	cout << cnt << " ";
	}
	if(cnt) ans++;
	cout << ans;
	return 0;
}
