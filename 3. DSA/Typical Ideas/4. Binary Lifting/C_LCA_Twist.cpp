#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<vector<int>> par;
vector<int> depth;

//binary lifting
void dfs(int nn, int pp, int dd){
    depth[nn] = dd;
    par[nn][0] = pp;

    for(int i=1;i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
    }

    for(auto v: g[nn]){
        if(v!=pp){
            dfs(v,nn,dd+1);
        }
    }
}

int lca(int u, int v)
{
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--){
        if(diff&(1<<i)){
            u = par[u][i];
        }
    }
    if(u==v) return u;

    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void solve()
{
    int n;cin>>n;
    g.resize(n+1); 
    par.assign(n+1,vector<int>(20,0));
    depth.assign(n+1,0);
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    int q; cin>>q;
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        int l = lca(x,y);
        int a = lca(x,z);
        int b = lca(y,z);
        if(a==l){
            cout<<b<<'\n';
        }else if(b==l){
            cout<<a<<'\n';
        }else{
            cout<<l<<'\n';
        }
    }
    g.clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}