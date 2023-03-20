#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
struct color
{
    int ntop;
    int ftop;
    int n;
    int f;
    int nf;
} x[100010][2];
int tmp[100010];

int main()
{
    int n, m;
    long long ans = 0;
    set<int> col;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> tmp[i];
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        x[c][i % 2].ntop = tmp[i];
        x[c][i % 2].ftop = i;
        x[c][i % 2].n += tmp[i];
        x[c][i % 2].f += i;
        x[c][i % 2].nf += i * tmp[i];
        x[c][i % 2].n %= MOD;
        x[c][i % 2].f %= MOD;
        x[c][i % 2].nf %= MOD;
        col.emplace(c);
    }
    for (auto i : col)
    {
        ans += x[i][0].ntop * x[i][0].f + x[i][0].ftop * x[i][0].n + x[i][0].nf;
        ans %= MOD;
        ans += x[i][1].ntop * x[i][1].f + x[i][1].ftop * x[i][1].n + x[i][1].nf;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}