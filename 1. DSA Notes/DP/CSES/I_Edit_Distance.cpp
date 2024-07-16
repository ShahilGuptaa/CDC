#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int dp[5002][5002];

void solve()
{
    string a,b; cin>>a>>b;
    int n = a.size();
    int m = b.size();

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(1+dp[i-1][j-1],min(1+dp[i][j-1],1+dp[i-1][j]));
                }
            }
        }
    }
    cout<<dp[n][m]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}