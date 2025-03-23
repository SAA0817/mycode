#include <bits/stdc++.h>
#include <unordered_map>
#define endl '\n'
using namespace std;
const int N = 1e6 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const double eps = 1e-2;
const long double pi = acos(-1);
typedef long long LL;
typedef pair<LL, LL> PII;
typedef long double LD;
typedef unsigned long long ull;
long double a[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long double sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i] / (n + 1);
    }
    printf("%.9Lf\n", sum * 2);
    for (int i = 2; i <= n; i++) printf("%.9Lf\n", sum);
    // cout << endl;
    return 0;
}