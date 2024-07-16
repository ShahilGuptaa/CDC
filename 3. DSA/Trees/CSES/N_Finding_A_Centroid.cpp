#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli n,ans;
vector<vector<lli>> g;
vector<lli> sub_sz;

void dfs(int nn, int pp)
{
    sub_sz[nn] = 1;
    for(auto v: g[nn])
    {
        if(v!=pp){
            dfs(v,nn);
            sub_sz[nn] += sub_sz[v];
        }
    }
}

void finding_centroid(int nn, int pp)
{
    int flag = 1;
    for(auto v: g[nn])
    {
        if(v!=pp)
        {
            if(sub_sz[v]>(n/2))
            {
                finding_centroid(v,nn);
                flag = 0;
            }
        }
    }
    if(flag) ans = nn;
}

void solve()
{
    cin>>n;
    g.resize(n+1); sub_sz.assign(n+1,0);
    for(int i=2;i<=n;i++)
    {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    finding_centroid(1,0);
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}