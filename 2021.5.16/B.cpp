#include<iostream>

using namespace std;

int T;
int num;

int main()
{
	scanf("%d", &T);
	for(int s = 1; s <= T; s++)
	{
		bool flag1 = 0, flag2 = 0, flagall = 1, flag3 = 1;
		scanf("%d", &num);
		for(int i = 1; i <= num; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			
			if(i == 1 && tmp != num) flag3 = 0;
			if(i == num && tmp != 1) flag3 = 0;
			if(tmp != i) flagall = 0;
			if(tmp == i && i == 1) flag1 = 1;
			if(tmp == i && i == num) flag2 = 1;
		}
		if(flag3) printf("%d\n", 3);
		else if(flagall) printf("%d\n", 0);
		else if(!flag2 && !flag1) printf("%d\n", 2);
		else printf("%d\n", 1);
	}
	
	return 0;
} 
