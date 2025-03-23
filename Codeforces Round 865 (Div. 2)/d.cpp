#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#define LL long long 

using namespace std;


const int MAXN = 3e3+5;

int t;
int n;
LL a[MAXN];
LL b[MAXN];
LL ans[MAXN];
int tmp;


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        int num = 0;
        int maxnum = 0;

        cout << "+ " << n+1 << endl;
        cin >> tmp;
        cout << "+ " << n << endl; //n 1 n-1 2 .....
        cin >> tmp;

        for(int i = 1; i <= n/2; i++)
        {
            ans[i*2-1] = n-i+1;
            ans[i*2] = i;
        }

        if(n % 2 == 1) ans[n] = n/2+1;

        num = 1;


        for(int i = 2; i <= n; i++)
        {
            cout << "? " << 1 << " " << i << endl;
            cin >> a[i];
            if(a[i] > maxnum)
            {
                num = i;
                maxnum = a[i];
            }
        }

        b[num] = 1;

        for(int i = 1; i <= n; i++)
        {
            if(i == num) continue;
            cout << "? " << num << " " << i << endl;
            cin >> b[i];
            b[i]++;
        }

        cout << "! ";

        for(int i = 1; i <= n; i++)
            cout << ans[b[i]] << " ";

        for(int i = 1; i <= n; i++)
            cout << ans[n-b[i]+1] << " ";

        cout << endl;

        cin >> tmp;

    }

    
    return 0;
}


//1 4 2 5 3 6


//6 1 5 2 4 3

//3 2 1 4 1
//4 1 2 3 4