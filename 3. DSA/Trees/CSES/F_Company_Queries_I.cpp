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
vector<vector<lli>> par;

void dfs(int nn, int pp)
{
    par[nn][0] = pp;
    for(int i=1;i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
    }
    for(auto v: g[nn]){
        if(v!=pp){
            dfs(v,nn);
        }
    }
}

lli query(int x, int k)
{
    lli ans = x;
    for(int i=0;i<20;i++)
    {
        if(k&(1<<i))
        {
            ans = par[ans][i];
        }
    }
    return ans;
}

void solve()
{
    lli n,q;cin>>n>>q;
    g.resize(n+1); 
    par.assign(n+1,vector<lli>(20,0));
    for(int i=2;i<=n;i++){
        int u = i, v; cin>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    while(q--)
    {
        int x,k; cin>>x>>k;
        if(query(x,k)) cout<<query(x,k)<<'\n';
        else cout<<"-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}