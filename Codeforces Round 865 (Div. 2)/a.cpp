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
int x, y;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        if(__gcd(x, y) == 1)
        {
            cout << 1 << endl;
            cout << x << " " << y << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << 1 << " " << y-1 << endl;
            cout << x << " " << y << endl;
        }

    }

    
    return 0;
}