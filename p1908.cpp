#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    int n;
    cin >> n;
    set<int> s;
    vector<pair<int, int>> v;
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.first;
        if (s.emplace(tmp.first).second)
        {
            tmp.second = num++;
            v.push_back(tmp);
        }
    }
    sort(v.begin(), v.end(), cmp);
    unsigned long long ans = 0;
    num = 1;
    for (auto i : v)
    {
        ans += (num > i.second ? num - i.second : 0);
        num++;
    }
    cout << ans;
    return 0;
}