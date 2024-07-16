#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
//Partial Sum on Trees

vector<vector<lli>> g,par;
vector<lli> depth, cnt;

void dfs(int nn,int pp, int dd)
{
    par[nn][0] = pp;
    depth[nn] = dd;
    for(int i=1;i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
    }
    for(auto v: g[nn])
    {
        if(v!=pp) dfs(v,nn,dd+1);
    }
}

int lca(int a, int b)
{
    if(depth[b]<depth[a]){
        swap(a,b);
    }
    int diff = depth[b] - depth[a];
    for(int i=0;i<20;i++)
    {
        if(diff&(1<<i)){
            b = par[b][i];
        }
    }
    if(a==b) return a;

    for(int i=19;i>=0;i--){
        if(par[a][i]!=par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

void push_up(int nn, int pp)
{
    for(auto v: g[nn]){
        if(v!=pp){
            push_up(v,nn);
            cnt[nn] += cnt[v];
        }
    }
}

void solve()
{
    lli n,m;cin>>n>>m;
    g.resize(n+1); depth.assign(n+1,0); cnt.assign(n+1,0);
    par.assign(n+1,vector<lli>(20,0));

    for(int i=2;i<=n;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    while(m--){
        int u,v; cin>>u>>v;
        int l = lca(u,v);
        cnt[u] += 1;
        cnt[v] += 1;
        cnt[l] -= 1;
        cnt[par[l][0]] -= 1;
    }
    push_up(1,0);
    for(int i=1;i<=n;i++) cout<<cnt[i]<<' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}