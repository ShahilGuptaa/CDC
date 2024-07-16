#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;

lli n;
vector<vector<lli>> g;
vector<lli> val,sub_sum,indp,outdp;
lli total = 0;

void indfs(int nn, int pp)
{
    sub_sum[nn] = val[nn];
    for(auto v: g[nn]){
        if(v!=pp){
            indfs(v,nn);
            sub_sum[nn] += sub_sum[v];
            indp[nn] += (indp[v] + sub_sum[v]);
        }
    }
}

void outdfs(int nn, int pp)
{
    if(pp==0) outdp[nn] = 0; //for root
    else outdp[nn] = outdp[pp] + (indp[pp] - (indp[nn]+sub_sum[nn])) + (total-sub_sum[nn]);
    for(auto v: g[nn])
    {
        if(v!=pp){
            outdfs(v,nn);
        }
    }
}

void solve()
{
    total = 0;
    cin>>n;
    g.resize(n+1); val.assign(n+1,0); sub_sum.assign(n+1,0); indp.assign(n+1,0); outdp.assign(n+1,0);
    for(int i=1;i<=n;i++) {
        cin>>val[i];
        total += val[i];
    }
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    indfs(1,0);
    outdfs(1,0);
    lli ma = -1, mi = INF;
    for(int i=1;i<=n;i++) 
    {
        lli ans = indp[i]+outdp[i];
        ma = max(ma,ans);
        mi = min(mi,ans);
    }
    cout<<ma<<' '<<mi<<'\n';
    g.clear();
}

int main()
{
    int t; cin>>t; while(t--)
    solve();
}