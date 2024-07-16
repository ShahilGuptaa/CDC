#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> vis,par;
set<set<int>> all_cycles;

void addEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs(int nn, int pp){
    vis[nn] = 2;
    par[nn] = pp;
    for(auto nei: g[nn])
    {
        if(nei==pp) continue;
        if(vis[nei]==1){
            dfs(nei,nn);
        }
        else if(vis[nei]==2){
            set<int> cycle;
            int temp = nn;
            while(temp!=nei){
                cycle.insert(temp);
                temp = par[temp];
            }
            cycle.insert(nei);
            all_cycles.insert(cycle);
        }
    }
    vis[nn] = 3;
}

void solve()
{
    int n = 13; //no, of vertices
    g.resize(n+1); vis.assign(n+1,1); par.assign(n+1,-1);
    addEdge(1, 2); addEdge(2, 3); addEdge(3, 4);
    addEdge(4, 6); addEdge(4, 7); addEdge(5, 6);
    addEdge(3, 5); addEdge(7, 8); addEdge(6, 10);
    addEdge(5, 9); addEdge(10, 9); addEdge(10, 11);
    addEdge(11, 12); addEdge(11, 13); addEdge(12, 13);

    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            dfs(i,0);
        }
    }
    for(auto s: all_cycles){
        for(auto i:s){
            cout<<i<<' ';
        }cout<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}