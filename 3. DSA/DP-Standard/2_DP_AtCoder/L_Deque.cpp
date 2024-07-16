#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int n;
vector<lli> a;
lli dp[3002][3002];

lli rec(int l, int r){
    if(l>=r){
        return a[l];
    }
    if(dp[l][r]!=-1) return dp[l][r];

    lli ans = max(a[l] - rec(l+1,r),a[r]-rec(l,r-1));

    return dp[l][r] = ans;
}

void solve()
{
    cin>>n;
    a.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0,n-1)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}