#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ok[10][10];
int num[10][10];
const int temp[10][10];
int n, m;

void mset(int i, int j, int o)
{
    for (int x = i - 1; x <= i + 1; x++)
        for (int y = j - 1; y <= j + 1; y++)
            ok[x][y] = o;
}

void dfs(int cnt)
{
    if(memcmp())
    {

    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (!ok[i][j])
            {
                mset(i, j, 1);
                dfs(cnt + num[i][j]);
                mset(i, j, 0);
            }
        }
}

void solve()
{
    memset(ok, 0, sizeof(ok));
    memset(num, 0, sizeof(num));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> num[i][j];

    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}