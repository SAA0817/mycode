#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN = 1e4+5;

string ans[MAXN];
string s;

int t;
int cnt;

int n;

bool check(string s)
{
    // if(s.size() < 3) return false;
    for(int i = 0; i < s.size()-2; i++)
        if(s[i] == 'b' && s[i+1] == 'i' && s[i+2] == 'e')
            return true;
    return false;
}

bool addans(string s)
{
    for(int i = 1; i <= cnt; i++)
    {
        // cout << "cmp:" << ans[i] << " " << s << endl;
        if(!strcmp(ans[i].c_str(), s.c_str()))
        {
            return false;
        }
    }
    ans[++cnt] = s;
    return true;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    string tmp = "a";

    cout << tmp.size();

    cin >> t;
    while(t--)
    {
        bool flag = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> s;
            
            if(check(s))
            {
                if(addans(s))
                {
                    cout << s << endl;
                    flag = 1;
                }
            }
        }
        if(!flag)
            cout << "Time to play Genshin Impact, Teacher Rice!" << endl;
        flag = 0;
            
    }




    return 0;
}