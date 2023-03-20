#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10009;
int fa[N];
int find(int x)
{
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        fa[a] = b;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int ans = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 'F')
        {
            merge(x, y);
        }
        else if (z == 'E')
        {
            cout << ((find(x) == find(y)) ? "Y" : "N") << '\n';
        }
    }

    return 0;
}