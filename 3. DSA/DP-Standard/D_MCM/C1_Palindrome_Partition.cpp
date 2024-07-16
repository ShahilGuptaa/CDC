#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[502][502];

int rec(int i, int j, string &s)
{
    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int f = 1;
    for(int k=0;k<=(j-i);k++){
        if(s[i+k]!=s[j-k]){
            f = 0;
            break;
        }
    }
    if(f) return dp[i][j] = 0;

    int ans = s.size() - 1;
    for(int k=i;k<j;k++){
        ans = min(ans, rec(i,k,s)+rec(k+1,j,s)+1);
    }
    return dp[i][j] = ans;
}

void solve()
{
    string s; cin>>s;
    int n = s.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1,s)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}