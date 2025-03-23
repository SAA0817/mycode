#include<iostream>
#include<cstring>
using namespace std;
bool flag;
int t,n;
char d;
string s,ans;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>d;

		cin >> s;
		// for(int i=0;i<n;i++)
		// {
		// 	cin>>s[i];
		// }
		
		for(int i=0;i<n;i++)
		{
			if(flag==0&&s[i]-'0'<=d-'0')
			{
				ans=ans+d;
				flag=1;
			}
			ans+=s[i];
		}
		if(flag==0)ans+=d;
		cout<<ans<<endl;
		ans="";
		//如何清空字符串
		flag=0;
	}
	return 0;
}