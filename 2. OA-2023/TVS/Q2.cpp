#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli, lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli maxSubArray(vector<lli> &nums)
{
    lli curMax = 0, maxTillNow = INT_MIN;
    for (auto c : nums)
        curMax = max(c, curMax + c),
        maxTillNow = max(maxTillNow, curMax);
    return maxTillNow;
}

void solve()
{
    lli n;
    cin >> n;
    vector<lli> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 1; i < n; i += 2)
    {
        v[i] *= -1;
    }
    lli ans = maxSubArray(v)*maxSubArray(v);
    for (int i = 0; i < n; i ++)
    {
        v[i] *= -1;
    }
    ans = max(ans,maxSubArray(v)*maxSubArray(v));

    cout<<ans<<'\n';
}

int main()
{
        solve();
}