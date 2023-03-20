#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
list<int> li;
int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    li.emplace_front(1);
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;

        for (auto it = li.begin(); it != li.end(); it++)
        {
            if (*it == k)
            {
                if (p)
                    // right
                    it++;
                li.insert(it, i);
            }
        }
    }
    cin >> m;
    while (m--)
    {
        int x;
        cin >> x;
        li.remove_if([x](int a) { return a == x; });
    }
    for (auto i : li)
        cout << i << ' ';

    return 0;
}