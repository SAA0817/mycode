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
int n;
int x1, x2, y1, y2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        x1 = min(x1, n - x1 + 1);
        y1 = min(y1, n - y1 + 1);
        x2 = min(x2, n - x2 + 1);
        y2 = min(y2, n - y2 + 1);

        int x = min(x1, y1);
        int y = min(x2, y2);

        cout << max(x - y, y - x) << endl;
        
    }
    
    
    

    return 0;
}