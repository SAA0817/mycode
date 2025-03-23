#include<iostream>

using namespace std;

int T;
int num;

int main()
{
	scanf("%d", &T);
	for(int s = 1; s <= T; s++)
	{
		scanf("%d", &num);
		if(num % 100 == 0) printf("%d\n", 1);
		else if(num % 50 == 0) printf("%d\n", 2);
		else if(num % 25 == 0) printf("%d\n", 4);
		else if(num % 20 == 0) printf("%d\n", 5);
		else if(num % 10 == 0) printf("%d\n", 10);
		else if(num % 5 == 0) printf("%d\n", 20);
		else if(num % 4 == 0) printf("%d\n", 25);
		else if(num % 2 == 0) printf("%d\n", 50);
		else printf("%d\n", 100);
	}
	
	return 0;
} 
