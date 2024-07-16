#include<bits/stdc++.h>
using namespace std;

int dp[102][100100];

void solve()
{
    int n;cin>>n;
    vector<int> x(n);
    int m = 0;
    for(int i=0;i<n;i++){
        cin>>x[i];
        m += x[i];
    }
    int tar = m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=tar;j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;

            if(i!=0 && j!=0)
            {
                dp[i][j] = dp[i-1][j];
                if(x[i-1]<=j)
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-x[i-1]]);
                }
            }
        }
    }
    int cnt = 0;
    for(int j=1;j<=tar;j++){
        if(dp[n][j]) cnt++;
    }
    cout<<cnt<<'\n';
    for(int j=1;j<=tar;j++){
        if(dp[n][j]) cout<<j<<' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}