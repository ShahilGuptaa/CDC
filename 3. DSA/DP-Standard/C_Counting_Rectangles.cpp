#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli n,m;
vector<vector<lli>> dp;
lli rec(int n,int m){
    if(n==0 || m==0) return 0;
    if(n==1) return m*(m+1)/2;
    if(m==1) return n*(n+1)/2;

    if(dp[n][m]!=-1) return dp[n][m];

    lli ans = 0;
    ans += rec(n-1,m) + rec(n,m-1) - rec(n-1,m-1) + (n)*(m);

    return dp[n][m] = ans;

}
void solve()
{
    cin>>n>>m;
    dp.assign(n+1,vector<lli>(m+1,-1));
    cout<<rec(n-1,m-1)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}