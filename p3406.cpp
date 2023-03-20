#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pri[1000000];
int p[1000000];
int main()
{
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> p[i];

    for (int i = 2; i <= n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        b += c;
        a = a > b ? b : a;
        pri[i] += a + pri[i - 1];
    }cerr << "======================\n";
    for (int i = 1; i <= n; i++)
    {
        cerr<<pri[i]<<' ';
    }
    cerr<<endl;
    ll ans = 0;
    cerr << "======================\n";
    for (int i = 2; i <= m; i++)
    {
        ll x, y;
        x = p[i];
        y = p[i - 1];

        if (x == y)
            continue;
        ll tmp = abs(pri[x] - pri[y]);
        ans += tmp;
        cerr << tmp << ' ' << p[i] << ' ' << p[i - 1] << endl;
    }
    cout << ans;

    return 0;
}