#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010];

//Top Down
int topdown(int n, int m, string &a, string &b){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i*j==0) dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i!=j && a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

void solve()
{
    string a,b; cin>>a;
    b = a;
    int n = a.size(), m = b.size();

    memset(dp,-1,sizeof(dp));
    cout<<topdown(n,m,a,b)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}