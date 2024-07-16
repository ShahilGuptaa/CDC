#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[101][1010];

void solve()
{
    lli n,tar = 0;cin>>n>>tar;
    vector<int> a(n);
    memset(dp,-1,sizeof(dp)); //[n][tar]

    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    //Initializing
    for(int i=0;i<=n;i++){
        for(int j=0;j<=tar;j++){
            if(j==0){
                dp[i][j] = 1;
            }
            else if(i==0){
                dp[i][j] = 0;
            }
        }
    }

    //Logix
    for(int i=1;i<=n;i++){
        for(int j=1;j<=tar;j++){
            dp[i][j] = dp[i-1][j];
            if(a[i-1]<=j){
                dp[i][j] += dp[i-1][j-a[i-1]];
            }
        }
    }
    cout<<dp[n][tar]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}