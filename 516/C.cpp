#include<cstdio>
#include<iostream>
#define LL long long
#define MAXN 100005

using namespace std;

char c;
int t[30];
int cnt = 1;
void read()
{
	c = getchar();
	while(c < 'a' || c > 'z') c = getchar();
    t[c - 'a' + 1]++;
	return;
}

int main()
{
	int n;
	scanf("%d\n", &n);
	for(int i = 1; i <= n; i++)
	    read();
	for(int i = 1; i <= n; i++)
	{
		while(!t[cnt]) cnt++;
		printf("%c", char(cnt + 'a' - 1));
		t[cnt]--;
	}
	return 0;
}
