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

int rec(int n, int c, vector<int> &wt, vector<int> &val)
{
    //base case
    if(n==0 || c<=0){
        return 0;
    }
    //cache check
    if(dp[n][c]!=-1) return dp[n][c];

    //transitions
    int ans = 0;
    ans = rec(n-1,c,wt,val);
    if(wt[n-1]<=c){
        ans = max(ans,val[n-1]+rec(n,c-wt[n-1],wt,val));
    }
    //save and return
    return dp[n][c] = ans;
}

void solve()
{
    lli n,c;cin>>n>>c;
    vector<int> wt(n),val(n);
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i];

    memset(dp,-1,sizeof(dp));

    cout<<rec(n,c,wt,val)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}