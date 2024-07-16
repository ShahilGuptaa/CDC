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

//Top Down -> give longest common substring ending at n,m
int topdown(int n, int m, string &a, string &b){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i*j==0) dp[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = 0;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}

void solve()
{
    string a,b; cin>>a>>b;
    int n = a.size(), m = b.size();

    memset(dp,-1,sizeof(dp));
    cout<<topdown(n,m,a,b)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}