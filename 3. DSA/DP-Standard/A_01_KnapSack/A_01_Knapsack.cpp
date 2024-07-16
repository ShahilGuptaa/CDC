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

int rec(vector<int> &wt,vector<int> &val,int C, int n){
    //Base case
    if(C<=0 || n==0){
        return 0;
    }
    //Memoization
    if(dp[n][C]!=-1) return dp[n][C];
    //transitions
    int ans = 0;
    ans = rec(wt,val,C,n-1);
    if(wt[n-1]<=C){
        ans = max( ans, val[n-1] + rec(wt,val,C-wt[n-1],n-1) );
    }
    //Save and return 
    return dp[n][C] = ans;
}

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
    cout<<rec(wt,val,C,n)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}