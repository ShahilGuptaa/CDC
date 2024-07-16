#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[101][1000100];

//Recursive
// int rec(int n,int x, vector<int> &coins){
//     if(x==0){
//         return 0;
//     }
//     if(n==0){
//         return mod;
//     }
//     if(dp[n][x]!=mod) return dp[n][x];

//     int ans = rec(n-1,x,coins);
//     if(coins[n-1]<=x){
//         ans = min(ans,1 + rec(n,x-coins[n-1],coins));
//     }
//     return dp[n][x] = ans;
// }

void solve()
{
    lli n,x;cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j==0) dp[i][j] = 0;
            else dp[i][j] = mod;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(coins[i-1]<=j){
                dp[i][j] = min(dp[i][j],1 + dp[i][j-coins[i-1]] );
            }
        }
    }

    int ans = dp[n][x];
    if(ans==mod) cout<<"-1\n";
    else cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}