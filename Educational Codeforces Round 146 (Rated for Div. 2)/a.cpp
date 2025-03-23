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
LL n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        if((n - k) % 2 == 0) cout << "YES" << endl;
        else if(n % 2 == 0) cout << "YES" << endl;
        else cout << "No" << endl;
        

    }
    
    
    

    return 0;
}