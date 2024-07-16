#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
lli n;
vector<lli> a;
vector<lli> pre;
lli dp[402][402];

lli rec(int l, int r)
{
    if(l==r){
        return 0;
    }
    if(dp[l][r]!=-1) return dp[l][r];

    lli ans = 1e14;
    for(int i=l;i<r;i++)
    {
        lli cost = (pre[r+1]-pre[l]);
        ans = min(ans,rec(l,i)+rec(i+1,r)+cost);
    }
    return dp[l][r] = ans;
}

void solve()
{
    cin>>n; a.resize(n); pre.resize(n+1);
    pre[0] = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pre[i+1] = pre[i]+a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}