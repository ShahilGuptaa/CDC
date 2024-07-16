#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> topo,vis;

void dfs(int nn){
    vis[nn] = 1;
    for(auto v: g[nn]){
        if(!vis[v]){
            dfs(v);
        }
    }
    topo.push_back(nn);
}

void solve()
{
    int n,m;cin>>n>>m;
    g.resize(n+1); vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(topo.begin(),topo.end());
    for(auto v: topo) cout<<v<<' ';
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}