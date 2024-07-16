#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
long long int dp[1000100][2];

void solve()
{
    int t; cin>>t;
    //dp[i][0] -> the number of ways to add rectangle to the 2*i squares s.t last line was orange
    //dp[i][1] -> the number of ways to add rectangle to the 2*i squares s.t last line was green

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=2;i<=1000000;i++){
        dp[i][0] = ( ((2*dp[i-1][0])%mod) + (dp[i-1][1]%mod) )%mod;
        dp[i][1] = ( (dp[i-1][0]%mod) + ((4*dp[i-1][1])%mod) )%mod;
    }

    while(t--){
        int n;cin>>n;
        int ans = (dp[n][0] + dp[n][1])%mod;
        cout<<ans<<'\n';
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}