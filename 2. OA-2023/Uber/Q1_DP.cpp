#include <bits/stdc++.h>
using namespace std;
unordered_map<char, vector<int>> m;
int mm, n;
int f(int i, int j, string &pass, vector<vector<int>> &dp)
{
    if (i == mm)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 1e9;
    int ss = m[pass[i]].size();
    for (auto &a : m[pass[i]])
    {
        ans = min(ans, 1 + min(abs(a - j), n - abs(a - j)) + f(i + 1, a, pass, dp));
    }
    return dp[i][j] = ans;
}
int main()
{
    string s, pass;
    cin >> s >> pass;
    n = s.size();
    mm = pass.size();
    for (int i = 0; i < n; i++)
    {
        m[s[i]].push_back(i);
    }
    vector<vector<int>> dp(mm, vector<int>(n, -1));
    cout << f(0, 0, pass, dp);
}