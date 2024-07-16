#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli bin_pow(lli a, lli b, int m) //return (a^b)%m in log(b)
{
    if(b==0) return 1;
    if(b==1)return a%m;
    lli ans = bin_pow(a,b/2,m)%m;
    if(b%2) return ((a%m)*((ans*ans)%m))%m;
    else return (ans*ans)%m;
}
void solve()
{
    string s,t; cin>>s>>t;
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n+2,vector<int>(m+1,-1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i*j==0) dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
        }
    }

    int i = n,j = m;
    string lcs;
    while(i>=1 && j>=1){
        if(s[i-1]==t[j-1]){
            lcs.push_back(s[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(lcs.begin(),lcs.end());
    cout<<lcs<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}