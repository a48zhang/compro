#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class point
{
  public:
    int x, y;
    double dis(point a);
    point(int x, int y)
    {
        this->x = x;
        this->y = y;
        return;
    };
};
double point::dis(point a)
{
    return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
}
vector<point> pt;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        pt.push_back(point{x, y});
    }
    sort(pt.begin(), pt.end(), [](point a, point b) { a.x + a.y < b.x + b.y; });
    double ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += pt[i - 1].dis(pt[i]);
    }
    cout << ans;
    return 0;
}