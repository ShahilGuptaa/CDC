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
vector<lli> par,outdp;
vector<ii> indp;
 
void indfs(int nn, int pp)
{
    indp[nn].F = 0;
    par[nn] = pp;
    for(auto v: g[nn]){
        if(v!=pp){
            indfs(v,nn);
            if(indp[v].F + 1 > indp[nn].F){
                indp[nn].S = max(indp[nn].S, indp[nn].F);
                indp[nn].F = indp[v].F + 1;
            }
            else{
                indp[nn].S = max(indp[nn].S, indp[v].F + 1);
            }
        }
    }
}
 
void outdfs(int nn, int pp)
{
    if(pp==0) outdp[nn] = 0; //for root
    else {
        outdp[nn] = 1 + outdp[pp];
        if(1 + indp[nn].F == indp[pp].F){
            outdp[nn] = max(outdp[nn],1 + indp[pp].S);
        }else{
            outdp[nn] = max(outdp[nn],1 + indp[pp].F);
        }
    }
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
    g.resize(n+1); par.assign(n+1,0); indp.assign(n+1,{-1,-1}); outdp.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    indfs(1,0);
    outdfs(1,0);
    for(int i=1;i<=n;i++) cout<<max(indp[i].F,outdp[i])<<' ';
    cout<<'\n';
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}