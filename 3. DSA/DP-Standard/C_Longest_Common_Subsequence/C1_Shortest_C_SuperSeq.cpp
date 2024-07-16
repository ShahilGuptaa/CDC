#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;
    
//Find shortest string 'c' s.t. a and b are subsequence of c
/*
AGGTAB GXTXAYB
ans = AGGXTXAYB
*/
int dp[1010][1010];
void solve()
{
    string a,b; cin>>a>>b;
    int n = a.size(), m = b.size();
    //len of Shortest Common Supersequence =  a.len + b.len - lcs(a,b)
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
    cout<<n+m-dp[n][m]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}