#include<iostream>
#include<bitset>
#define endl '\n'
using namespace std;

int T;
int n, m;

const int MAXN = 205;

int a[MAXN][MAXN];
int cnt1, cnt2, cnt3;


int f1(int num)
{
    return (16383<<14) + num;
}

int f2(int num)
{
    return (num << 14) + 16383;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;

    while(T--)
    {
        cnt1 = 0; cnt2 = 0; cnt3 = 0;
        cin >> n >> m;
        cout << n*m << endl;

        // for(int i = 1; i <= 10; i++)
        //     cout << (f1(++cnt1) | f2(++cnt2)) << " ";
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cout << 65536 * i + j << " ";

                // if(i % 2 == 0) a[i][j] = cnt3;
                // else if(j % 2 == 1) a[i][j] = f1(cnt1);
                // else a[i][j] = f2(cnt2);
            }
            cout << endl;
        }
        
        // cout << (a[1][1] | a[2][1] | a[1][2] | a[2][2]) << endl;
        // cout << (a[3][3] | a[4][3] | a[3][4] | a[4][4]) << endl;
        
    }


    return 0;
}