#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char x[1010][1010];
bool used[1010][1010];
int n, m;
int ans;

bool t(int i, int j, char t)
{
    if (x[i][j] == t && !used[i][j])
    {
        used[i][j] = 1;
        return true;
    }
    return false;
}

void dfs(int i, int j, int cnt)
{
    if (cnt > ans)
        ans = cnt;
    if (x[i][j] == '0')
    {
        if (t(i + 1, j, '1'))
            dfs(i + 1, j, cnt + 1), used[i + 1][j] = 0;
        if (t(i, j + 1, '1'))
            dfs(i, j + 1, cnt + 1), used[i][j + 1] = 0;
        if (t(i - 1, j, '1'))
            dfs(i - 1, j, cnt + 1), used[i - 1][j] = 0;
        if (t(i, j - 1, '1'))
            dfs(i, j - 1, cnt + 1), used[i][j - 1] = 0;
    }
    else if (x[i][j] == '1')
    {
        if (t(i + 1, j, '0'))
            dfs(i + 1, j, cnt + 1), used[i + 1][j] = 0;
        if (t(i, j + 1, '0'))
            dfs(i, j + 1, cnt + 1), used[i][j + 1] = 0;
        if (t(i - 1, j, '0'))
            dfs(i - 1, j, cnt + 1), used[i - 1][j] = 0;
        if (t(i, j - 1, '0'))
            dfs(i, j - 1, cnt + 1), used[i][j - 1] = 0;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x[i][j];
        }
    }
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        ans = 0;
        dfs(i, j, 0);
        cout << ans << '\n';
    }

    return 0;
}