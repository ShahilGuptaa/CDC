#include<bits/stdc++.h>
using namespace std;
 
using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli mod = 1000000007;
 
vector<vector<lli>> g;
vector<lli> depth;
 
void dfs(int nn, int pp, int dd)
{
    depth[nn] = dd;
    for(auto v: g[nn])
    {
        if(v!=pp)
        {
            dfs(v,nn,dd+1);
        }
    }
}
 
void solve()
{
    lli n;
    cin>>n;
    g.resize(n+1);
    depth.resize(n+1);
 
    for(int i=1;i<n;i++)
    {
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,0);
    int a=1;
    for(int i=1;i<=n;i++)
    {
        if(depth[i]>depth[a])
        {
            a = i;
        }
    }
    dfs(a,0,0);
    lli ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans = max(ans,depth[i]);
    }
    cout<<ans<<'\n';
    
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    solve();
}
