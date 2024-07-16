#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[1010][1010];

int rec(int n,vector<int> &coins, int sum)
{
    //Base case
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    //cache check
    if(dp[n][sum]!=-1) return dp[n][sum];

    //transitions
    int ans = rec(n-1,coins,sum);
    if(coins[n-1]<=sum){
        ans += rec(n,coins,sum-coins[n-1]);
    }

    //save and return
    return dp[n][sum] = ans;
}

int topdown(int n,vector<int> &coins, int sum)
{
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(coins[i-1]<=j){
                dp[i][j] += dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[n][sum];
}

void solve()
{
    lli n,sum;cin>>n>>sum;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    memset(dp,-1,sizeof(dp));
    cout<<rec(n,coins,sum)<<'\n';
    cout<<topdown(n,coins,sum)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}