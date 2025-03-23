#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
#include<vector>
#include<map>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 405;
const int mod = 1e9+7;

int t;
int n, m;
int l, r;
int num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> l >> r;
        int ans = 0;
        
        for(int i = l; i <= r; i++)
        {

            int minnum = 10;
            int maxnum = 0;

            int tmp = i;

            while(tmp)
            {
                minnum = min(minnum, tmp % 10);
                maxnum = max(maxnum, tmp % 10);
                tmp /= 10;
            }

            if(ans <= maxnum - minnum)
            {
                ans = maxnum - minnum;
                num = i;
            }

            if(ans == 9) break;
        }
        cout << num << endl;
    }

    

    return 0;
}