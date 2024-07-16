#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli, lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[2002];

bool is_pelin(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int rec(int i, string &s)
{
    int n = s.size();
    if (i >= n - 1 || is_pelin(i, n - 1, s))
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int ans = s.size() - 1;
    for (int k = i; k < n - 1; k++)
    {
        int f = is_pelin(i, k, s);
        if (f)
        {
            ans = min(ans, 1 + rec(k + 1, s));
        }
    }
    return dp[i] = ans;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, s) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}