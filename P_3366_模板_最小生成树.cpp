#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int v[N][N];
int vis[N];
int main()
{
    int n, m;
    int ans = 0;
    cin >> n >> m;
    memset(v, 0x3f3f3f3f, sizeof(v));
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[x][y] = z;
        v[y][x] = z;
    }
    vis[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        int pt = 0, m = 1e6;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] || v[i][j] == 0)
                continue;
            if (v[i][j] < m)
            {
                pt = j;
                m = v[i][j];
            }
        }
        if (pt)
        {
            cerr << "connect " << pt << " value " << m << '\n';
            vis[pt] = 1;
            ans += m;
        }
        else
            break;
    }

    cout << ans;
    return 0;
}