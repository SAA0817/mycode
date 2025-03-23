#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if(b > a) swap(a, b);
	if(c > a) swap(a, c);
	if(a >= b && a >= c)
	{
		if(b + c > a)
			cout << 0;
		else
		    cout << a - (b+c) + 1;
		return 0;
	}
	return 0;
}
