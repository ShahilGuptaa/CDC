#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int dp[110][1000010];

int topdown(int n,vector<int> &coins, int sum)
{
    for(int j=1;j<=sum;j++){
        dp[0][j] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j]%mod;
            if(coins[i-1]<=j){
                dp[i][j] += dp[i][j-coins[i-1]];
                dp[i][j]%=mod;
            }
        }
    }
    return dp[n][sum]%mod;
}

void solve()
{
    int n,sum;
    cin>>n>>sum;

    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    cout<<topdown(n,coins,sum)<<'\n';
}

int main()
{
    solve();
}