#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

//Multiple occurences of the same item is allowed now
int dp[1010][1010];

void solve()
{
    lli n,c;cin>>n>>c;
    vector<int> wt(n),val(n);
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i];

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            if(i*j==0) dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++){
            dp[i][j] = dp[i-1][j];
            if(wt[i-1]<=j){
                dp[i][j] = max(dp[i][j],val[i-1]+dp[i][j-wt[i-1]]);
            }
        }
    }
    cout<<dp[n][c]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}