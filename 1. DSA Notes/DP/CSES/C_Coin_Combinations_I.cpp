#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli dp[1000100];

lli topdown(int n,vector<int> &coins, int sum)
{
    dp[0] = 1;
    for(int j=1;j<=sum;j++)
    {
        for(int i=1;i<=n;i++)
        { 
            if(coins[i-1]<=j){
                dp[j] += dp[j-coins[i-1]];
                dp[j]%=mod;
            }
        }
    }
    return dp[sum]%mod;
}

void solve()
{
    lli n,sum;cin>>n>>sum;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    cout<<topdown(n,coins,sum)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}