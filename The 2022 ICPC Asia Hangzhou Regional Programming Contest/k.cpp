#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>

#define endl '\n'

using namespace std;
using LL = long long;

const int MAXN = 1e6+5;

int n, q;
int tot;
LL c[30][30];
bool vis[30];
LL ans, fans;

struct trie{
    int ch[30];
    int size[30];
}t[MAXN];


void add(string s)
{
    int p = MAXN-1;
    for(int i = 0; i < s.size(); i++)
    {
        int num = s[i] - 'a';
        for(int j = 0; j < 26; j++)
            c[num][j] += t[p].size[j];

        t[p].size[num]++;

        if(!t[p].ch[num])
        {
            t[p].ch[num] = ++tot;
        }
        
        p = t[p].ch[num];

        if(i == s.size()-1)
        {
            for(int j = 0; j < 26; j++)
                fans += t[p].size[j];
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    string s;

    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        add(s);
    }

    for(int i = 1; i <= q; i++)
    {
        cin >> s;

        memset(vis, 0, sizeof(vis));
        ans = fans;

        for(int j = 0; j < 26; j++)
        {
            int num = s[j] - 'a';
            vis[num] = 1;
            for(int k = 0; k < 26; k++)
            {
                if(!vis[k])
                    ans += c[num][k];

            }
        }
        cout << ans << endl;
    }    


    return 0;
}