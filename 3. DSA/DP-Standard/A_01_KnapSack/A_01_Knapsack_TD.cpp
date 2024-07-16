#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[1010][1010]; //[n][C]
void solve()
{
    int n,C;cin>>n>>C;
    memset(dp,-1,sizeof(dp));

    vector<int> wt(n),val(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    //Initializing the matrix
    for(int i=0;i<=n;i++){
        for(int j=0;j<=C;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=C;j++){
            dp[i][j] = dp[i-1][j];
            if(wt[i-1]<=j){
                dp[i][j] = max(dp[i][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }
    cout<<dp[n][C]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}