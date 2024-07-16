#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;

lli dp[100010][102]; //dp[n][last]

lli rec(int n,int e, vector<int> &a, int &m)
{
    if(n==1){
        if(a[0]==e || a[0]==0) return 1;
        else return 0;
    }
    if(a[n-1]!=e && a[n-1]!=0) return 0;

    //cache check
    if(dp[n][e]!=-1) return dp[n][e];

    //transitions
    lli ans = 0;
    ans += rec(n-1,e,a,m)%mod;
    if(e<m) ans += rec(n-1,e+1,a,m)%mod;
    if(e>1) ans += rec(n-1,e-1,a,m)%mod;
    ans = (ans+mod)%mod;

    return dp[n][e] = ans%mod;
}
void solve()
{
    int n,m;cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));

    lli ans = 0;
    for(int i=1;i<=m;i++){
        ans += rec(n,i,a,m)%mod;
    }
    cout<<ans%mod<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}