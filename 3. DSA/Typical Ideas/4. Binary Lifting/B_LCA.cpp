#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<vector<int>> par;
vector<int> depth;

//Best implementation
void dfs(int nn,int pp, int dd)
{
    depth[nn] = dd;
    par[nn][0] = pp;

    //note if it goes beyond the tree we are making the ancestor or 2^i th parent as 0
    for(int i=1;i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
    }

    for(auto v: g[nn]){
        if(v!=pp){
            dfs(v,nn,dd+1);
        }
    }
}

//O(20) per query
int lca(int u, int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    //uplifting
    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--)
    {
        if((diff&(1<<i))){
            u = par[u][i];
        }
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[u][0];
}

void solve()
{
    int n;cin>>n;
    g.resize(n+1); par.assign(n+1,vector<int>(20,0));
    depth.assign(n+1,0);
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
        cout<<lca(u,v)<<'\n';
    }
}

int main()
{
    solve();
}