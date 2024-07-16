#include<bits/stdc++.h>
using namespace std;
 
using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;
 
lli n,x;
vector<vector<lli>> g;
vector<lli> sub_sz,indp,outdp;
 
void indfs(int nn, int pp)
{
    sub_sz[nn] = 1;
    for(auto v: g[nn]){
        if(v!=pp){
            indfs(v,nn);
            sub_sz[nn] += sub_sz[v];
            indp[nn] += (indp[v] + sub_sz[v]);
        }
    }
}
 
void outdfs(int nn, int pp)
{
    if(pp==0) outdp[nn] = 0;
    else outdp[nn] = outdp[pp] + (indp[pp] - (indp[nn]+sub_sz[nn])) + (n-sub_sz[nn]);
    for(auto v: g[nn])
    {
        if(v!=pp){
            outdfs(v,nn);
        }
    }
}
 
void solve()
{
    cin>>n;
    g.resize(n+1); sub_sz.assign(n+1,0); indp.assign(n+1,0); outdp.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    indfs(1,0);
    outdfs(1,0);
    for(int i=1;i<=n;i++) cout<<indp[i]+outdp[i]<<' ';
    cout<<'\n';
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
