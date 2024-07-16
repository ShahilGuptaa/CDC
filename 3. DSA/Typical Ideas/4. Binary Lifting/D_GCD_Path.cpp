#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<vector<int>> par;
vector<vector<int>> dp;
vector<int> depth;
vector<int> val;

//Best implementation
void dfs(int nn,int pp, int dd)
{
    depth[nn] = dd;
    par[nn][0] = pp;
    dp[nn][0] = val[nn];

    //note if it goes beyond the tree we are making the ancestor or 2^i th parent as 0
    for(int i=1;i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
        dp[nn][i] = __gcd(dp[nn][i-1],dp[par[nn][i-1]][i-1]);
    }
    for(auto v: g[nn]){
        if(v!=pp){
            dfs(v,nn,dd+1);
        }
    }
}

//O(20) per query
int gcd(int u, int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    //uplifting
    int diff = depth[u] - depth[v];
    int ans = 0;
    for(int i=19;i>=0;i--)
    {
        if((diff&(1<<i)))
        {
            ans = __gcd(ans,dp[u][i]);
            u = par[u][i];
        }
    }
    if(u==v) return __gcd(ans,val[u]);

    for(int i=19;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            ans = __gcd(ans,dp[v][i]);
            v = par[v][i];
            ans = __gcd(ans,dp[u][i]);
            u = par[u][i];
        }
    }
    ans = __gcd(ans,val[u]);
    ans = __gcd(ans,val[v]);
    return __gcd(ans,val[par[u][0]]);
}

void solve()
{
    int n;cin>>n;
    g.resize(n+1); 
    val.resize(n+1);
    par.assign(n+1,vector<int>(20,0));
    dp.assign(n+1,vector<int>(20,0));
    depth.assign(n+1,0);
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=0;i<n-1;i++)
    {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0,0);
    int q; cin>>q;
    while(q--){
        int u,v; cin>>u>>v;
        cout<<gcd(u,v)<<'\n';
    }
    g.clear(); val.clear();
}

int main()
{
    int t; cin>>t; while(t--)
    solve();
}