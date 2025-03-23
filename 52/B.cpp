#include<cstdio>
#include<iostream>

using namespace std;

char c;
long long m, n;

long long read()
{
	c = getchar();
	long long res = 0;
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
	n = read(); m = read();
	long long num = 0;
	if(n < m * 2)
	    cout << 0 << " ";
	else
	    cout << n - (m * 2) << " ";
	if(m == 0)
	{
		cout << n;
		return 0;
	}
	    
	for(int i = 1; i <= n - 1; i++)
	{
		num += i;
		if(num >= m)
		{
			cout << n - i - 1;
			return 0;
		}
	}
	return 0;
}

