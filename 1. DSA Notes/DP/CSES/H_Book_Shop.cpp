#include<bits/stdc++.h>
using namespace std;

int dp[1002][100100];

void solve()
{
    int n,x;cin>>n>>x;
    vector<int> price(n),pages(n);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(i*j==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(price[i-1]<=j){
                dp[i][j] = max(dp[i][j],pages[i-1] + dp[i-1][j-price[i-1]]);
            }
        }
    }
    cout<<dp[n][x]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}