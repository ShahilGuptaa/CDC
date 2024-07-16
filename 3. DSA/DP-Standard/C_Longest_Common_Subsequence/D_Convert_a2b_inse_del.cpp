#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010];
void solve()
{
    string a,b; cin>>a>>b;
    int n = a.size(), m = b.size();
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i*j==0){
                dp[i][j] = 0;
            }
            else
            {
                if(a[i-1]==b[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int lcs = dp[n][m];
    int deleted = a.size()-lcs;
    int inserted = b.size()-lcs;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}