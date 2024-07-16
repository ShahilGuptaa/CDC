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
    string s; cin>>s;
    string p = s;
    int n = s.size();

    reverse(p.begin(),p.end());

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i*j)
            {
                if(s[i-1]==p[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout<<dp[n][n]<<'\n';
    int i=n,j=n;
    string lps;
    while(i>=1 && j>=1){
        if(s[i-1]==p[j-1]){
            lps += s[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(lps.begin(),lps.end());
    cout<<lps<<'\n';

    //Minimum no. of deletion to make a string pelindrome 
    // = string.len - lps.len
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}