#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
#define F first
#define S second

lli n,m;
vector<vector<lli>> g;
int dp[11][2000];

lli paths_count(int nn, int mask)
{
    if(mask+1==(1<<n)) return 1; //we can only stop here

    if(dp[nn][mask]!=-1) return dp[nn][mask];

    int ans = __builtin_popcount(mask)>=2 ? 1 : 0; //either we can stop here

    for(auto v: g[nn]){
        if(mask&(1<<(v-1))) continue;
        ans += paths_count(v,mask|(1<<(v-1)));
    }
    return dp[nn][mask] = ans;
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        g[0].push_back(i);
        g[i].push_back(0);
    }
    cout<<paths_count(0,0)/2<<'\n';

    g.clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}