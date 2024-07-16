#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

vector<vector<lli>> g;
vector<vector<lli>> par,dis;
vector<lli> depth;

void dfs(int nn, int pp, int dd)
{
    par[nn][0] = pp;
    dis[nn][0] = 1;
    depth[nn] = dd;
    for(int i=1;i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
        dis[nn][i] = dis[nn][i-1] + dis[par[nn][i-1]][i-1];
    }
    for(auto v: g[nn]){
        if(v!=pp){
            dfs(v,nn,dd+1);
        }
    }
}

lli query(int a, int b)
{
    if(depth[a]>depth[b]){
        swap(a,b);
    }
    int diff = (depth[b] - depth[a]);
    lli ans = diff;
    for(int i=0;i<20;i++)
    {
        if(diff&(1<<i)){
            b = par[b][i];
        }
    }
    if(a==b) return ans;

    for(int i=19;i>=0;i--)
    {
        if(par[a][i]!=par[b][i])
        {
            ans += dis[a][i]; //first add it to answer then only update
            a = par[a][i];
            ans += dis[b][i];
            b = par[b][i];
        }
    }
    return (ans+2);
}

void solve()
{
    lli n,q;cin>>n>>q;
    g.resize(n+1); depth.assign(n+1,0);
    par.assign(n+1,vector<lli>(20,0));
    dis.assign(n+1,vector<lli>(20,0));
    for(int i=2;i<=n;i++)
    {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    while(q--)
    {
        int x,k; cin>>x>>k;
        cout<<query(x,k)<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}