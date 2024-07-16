#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> topo,indeg;

void khan(){
    //min heap for lexiographically smallest topo order
    priority_queue<int,vector<int>,greater<int>> q; //use prioirity queue for lexiographically largest ans smallest topo
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.top();
        q.pop(); topo.push_back(cur);
        for(auto v: g[cur]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }
    for(auto v: topo) cout<<v<<' ';
    cout<<'\n';
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1); indeg.assign(n+1,0);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        indeg[v]++;
    }
    khan();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}