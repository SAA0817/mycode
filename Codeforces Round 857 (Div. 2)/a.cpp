#include<iostream>

using namespace std;

int T;
const int MAXN = 105;
int n;
int a[MAXN];
int cnt;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>T;

    while(T--)
    {
        cnt = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(a[i] > 0) cnt++;
        }

        for(int i = 1; i <= cnt; i++) cout << i << " ";
        for(int i = cnt + 1; i <= n; i++) cout << cnt-(i-cnt) << " ";
        cout << endl;

        for(int i = 1; i <= (n-cnt); i++) cout << 1 << " " << 0 << " ";
        for(int i = (n-cnt)*2+1; i <= n; i++) cout << i - (n-cnt)*2 << " ";
        cout << endl;
    }


    return 0;
}