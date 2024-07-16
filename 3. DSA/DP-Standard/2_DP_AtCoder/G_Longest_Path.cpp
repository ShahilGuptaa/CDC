#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

vector<vector<int>> g;
vector<int> dp;

int rec(int i){ //longest path starting at i
    if(g[i].size()==0){
        return 0;
    }
    //cache check
    if(dp[i]!=-1) return dp[i];

    //transitions
    int ans = 0;
    for(auto nei: g[i]){
        ans = max(ans,1 + rec(nei));
    }
    return dp[i] = ans;
}
void solve()
{
    lli n,m;cin>>n>>m;
    g.resize(n+1); dp.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,rec(i)); 
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}