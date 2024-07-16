#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

lli n,cap;
vector<lli> v,w;
lli dp[102][100100];

lli rec(int level, lli val){ //return min weight required to make val
    if(val<0) return 1e9+1;
    if(val==0) return 0;
    if(level==n) return 1e9+1;

    if(dp[level][val]!=-1) return dp[level][val];

    lli ans = 1e9+1;
    ans = min(w[level] + rec(level+1,val-v[level]),rec(level+1,val));

    return dp[level][val] = ans;
}

void solve()
{
    cin>>n>>cap;
    v.resize(n); w.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    lli ans = 1e9 + 1;
    for(int p=0;p<=100001;p++){
        lli req = rec(0,p);
        if(cap>=req) ans = p;
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}