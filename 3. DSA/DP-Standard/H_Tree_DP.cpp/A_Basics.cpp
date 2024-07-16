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
vector<lli> sub_sz;

void dfs(int nn, int pp, int dd)
{
    sub_sz[nn] = 1;
    for(auto v: g[nn]){
        if(v!=pp){
            dfs(v,nn,dd+1);
            sub_sz[nn] += sub_sz[v];
        }
    }
}

void solve()
{
    lli n,x;cin>>n>>x;
    g.resize(n+1); sub_sz.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(x,0,0);
    for(int i=1;i<=n;i++) cout<<sub_sz[i]<<' ';
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}