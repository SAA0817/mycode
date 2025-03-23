#include<iostream>
#define endl '\n'
using namespace std;

int T;
int n, m;

const int MAXN = 205;

int a[MAXN][MAXN];
int cnt1, cnt2;


int f1(int num)
{
    return (32768<<16) + num;
}

int f2(int num)
{
    return (num << 16) + 65536;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>T;

    while(T--)
    {
        cnt1 = 0; cnt2 = 0;
        cin >> n >> m;
        cout << n*m << endl;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(j % 2 == 1) cout << f1(++cnt1) << " ";
                else cout << f2(++cnt2) << " ";
            }
            cout << endl;
        }
            
        
    }


    return 0;
}