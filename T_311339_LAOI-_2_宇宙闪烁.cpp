#include <bits/stdc++.h>
using namespace std;
int n, q;
const int M = 200009;
int a[M];
int ind[M / 100];
int at(int i)
{
    int ret = ind[i / 100];
    for (int b = i - (i % 100) + 1; b <= i; b++)
        ret += a[b];
    return ret;
}
void solve(int l, int r)
{
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    int prev = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp - prev;
        prev = tmp;
        if (i % 100 == 0)
        {
            ind[i / 100] = tmp;
        }
    }

    while (q--)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;

            a[l] = v - at(l - 1);
            a[r + 1] = at(r + 1) - v;
            for (int i = l - (l % 100); l <= r; l += 100)
                ind[i] = v;

            memset(a + l + 2, 0, sizeof(int) * (r - l));

            // n = 12; start = 3
            // l r = 4 6
            // 1 2 3 4 5 6 7 8 9 10 11 12
            //     |
        }
        else
        {
            int l, r;
            cin >> l >> r;
        }
    }
}