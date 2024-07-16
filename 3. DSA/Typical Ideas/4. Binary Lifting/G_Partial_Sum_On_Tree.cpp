#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define F first
#define S second

vector<vector<lli>> g, par;
vector<lli> value;
vector<lli> depth;

//prefix[node] = distance to get to that node from root, i.e, 1
//note prefix will work only if the the operation is sum or xor
//for other types of queries use the previous approach only

void dfs(lli nn, lli pp, lli dd)
{
    par[nn][0] = pp;
    depth[nn] = dd;

    for(lli i=1;i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
    }

    for(auto v: g[nn]){
        if(v!=pp){
            dfs(v,nn,dd+1);
        }
    }
}

lli lca(lli u, lli v)
{
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    lli diff = depth[u] - depth[v];
    for(lli i=19;i>=0;i--)
    {
        if((diff&(1<<i))){
            u = par[u][i];
        }
    }
    if(u==v) return u;

    for(lli i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void fin_dfs(lli nn, lli pp)
{
    for(auto v: g[nn]){
        if(v!=pp){
            fin_dfs(v,nn);
        }
    }
    value[pp] += value[nn];
}

void solve()
{
    lli n;cin>>n;
    g.resize(n+1); depth.assign(n+1,0);
    value.assign(n+1,0);
    par.assign(n+1,vector<lli>(20,0));

    for(lli i=0;i<n-1;i++){
        lli u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1,0,0);

    lli q; cin>>q;
    while(q--){
        lli u,v,x;
        cin>>u>>v>>x;
        lli l = lca(u,v);
        value[u] += x;
        value[v] += x;
        value[l] -= x;
        value[par[l][0]] -= x; 
    }
    fin_dfs(1,0);
    for(lli i=1;i<=n;i++){
        cout<<value[i]<<' ';
    }cout<<'\n';

    g.clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}