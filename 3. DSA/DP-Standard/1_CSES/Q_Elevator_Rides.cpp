#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;
lli dp[21][2100000];
lli n,x;
vector<lli> wt;
lli rec(int n, lli mask){
    if(n==0){
        return 0;
    }
    if(dp[n][mask]!=-1) return dp[n][mask];

    lli wt_taken = wt[n-1];
    
}

void solve()
{
    cin>>n>>x;
    wt.resize(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    sort(wt.begin(),wt.end());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}