#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
#define F first
#define S second
vector<vector<ii>> g;
vector<vector<long long int>> par,dp;
vector<int> depth;
map<ii,int> weight;

void dfs(int nn, int pp, int dd)
{
    par[nn][0] = pp;
    depth[nn] = dd;
    dp[nn][0] = weight[{nn,pp}];

    for(int i=1;i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
        dp[nn][i] = dp[nn][i-1] + dp[par[nn][i-1]][i-1];
    }

    for(auto v: g[nn]){
        if(v.F!=pp){
            dfs(v.F,nn,dd+1);
        }
    }
}

long long int path_sum(int u, int v)
{
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    long long int ans = 0;
    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--)
    {
        if((diff&(1<<i)))
        {
            ans += dp[u][i];
            u = par[u][i];
        }
    }
    if(u==v) return ans;

    for(int i=19;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            ans += dp[u][i];
            u = par[u][i];
            ans += dp[v][i];
            v = par[v][i];
        }
    }
    ans += weight[{u,par[u][0]}];
    ans += weight[{v,par[v][0]}];
    return ans;
}


void solve()
{
    int n;cin>>n;
    g.resize(n+1); depth.assign(n+1,0);
    par.assign(n+1,vector<long long int>(20,0));
    dp.assign(n+1,vector<long long int>(20,0));

    for(int i=0;i<n-1;i++)
    {
        int u,v,wt; cin>>u>>v>>wt;
        weight[{u,v}] = wt;
        weight[{v,u}] = wt;
        
        g[u].push_back({v,wt}); g[v].push_back({u,wt});
    }
    weight[{1,0}] = 0;
    dfs(1,0,0);

    int q; cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<path_sum(u,v)<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}