#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli dp[1000010];

lli rec(lli sum){
    if(sum==0){
        return 1;
    }
    if(dp[sum]!=-1) return dp[sum];

    lli ans = 0;
    for(int i=1;i<=6;i++){
        if(i<=sum){
            ans += rec(sum-i);
            ans%=mod;
        }
    }
    return dp[sum] = ans;
}

void solve()
{
    lli n;cin>>n;
    memset(dp,-1,sizeof(dp));

    cout<<rec(n)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}