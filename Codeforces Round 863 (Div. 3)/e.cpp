#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<vector>
#include<map>
#include<queue>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 2e5+5;

int t;
LL n;
LL x1, x2, y1, y2;
int ans[20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        LL res = 0;
        int cnt = 0;
        while(n)
        {
            
            int num = n % 9;
            n /= 9;
            if(num >= 4) num++;
            ans[++cnt] = num;
        }
        for(int i = cnt; i >= 1; i--)
            cout << ans[i];
        cout << endl;
    }
    
    
    

    return 0;
}