#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli rec(int level,int peaks,vector<lli> &a,vector<vector<lli>> &dp){

    if(peaks==0) return 0;
    if(level>=a.size()) return INF;

    if(dp[level][peaks]!=-1) return dp[level][peaks];

    lli ans = rec(level+1,peaks,a,dp);
    lli le,ri8;
    if(level-1<0) le = 0;
    else le = a[level-1];

    if(level+1>=a.size()) ri8 = 0;
    else ri8 = a[level+1];

    lli cost =  max(0ll,1 + max(le,ri8) - a[level]);
    ans = min(ans,cost + rec(level+2,peaks-1,a,dp));

    return dp[level][peaks] = ans;
}

void solve()
{
    lli n,k;cin>>n>>k;
    vector<lli> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<vector<lli>> dp(n+1,vector<lli>(k+1,-1));
    lli ans = rec(0,k,a,dp);
    if(ans>=INF) cout<<"NOT POSSIBLE\n";
    else cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}