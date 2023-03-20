#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500][500];
int n, m, x, y;
void dfs(int x, int y, int cnt)
{
    if (max(x, y) > n)
        return;
    if (min(x, y) < 1)
        return;
    if (a[x][y] == 0 || a[x][y] > cnt)
        a[x][y] = cnt;
    dfs(x + 2, y + 1, cnt + 1);
    dfs(x + 1, y + 2, cnt + 1);
    dfs(x - 1, y + 2, cnt + 1);
    dfs(x - 2, y + 1, cnt + 1);
    dfs(x + 1, y - 2, cnt + 1);
    dfs(x + 2, y - 1, cnt + 1);
    dfs(x - 2, y - 1, cnt + 1);
    dfs(x - 1, y - 2, cnt + 1);
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    dfs(x, y, 0);
    a[x][y] = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[x][y] == -1)
                cout << 0 << ' ';
            else if (a[x][y] == 0)
                cout << -1 << ' ';
            else
                cout << a[x][y] << ' ';
        }
        cout << '\n';
    }

    return 0;
}