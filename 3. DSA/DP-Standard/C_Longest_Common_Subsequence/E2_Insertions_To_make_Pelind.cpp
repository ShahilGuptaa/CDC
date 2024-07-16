#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[1010][1010];
void solve()
{
    string a; cin>>a;
    string b = a; 
    reverse(b.begin(),b.end());
    int n = a.size();

    memset(dp,-1,sizeof(dp));
    //LCS
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i*j==0) dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int lps = dp[n][n];
    
    //minimum no. of insertions
    //min(insertions) = min(deletions)

    cout<<n - lps<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}