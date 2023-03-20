#include <bits/stdc++.h>
using namespace std;
int a[20009], dp[20009];
int main()
{
    int n, v;
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= v; j++)
        {
            if (dp[j - a[i]] < a[i])
                continue;
            dp[j] = min(dp[j], dp[j - a[i]] - a[i]);
        }
    }
    cout << dp[v];
    return 0;
}