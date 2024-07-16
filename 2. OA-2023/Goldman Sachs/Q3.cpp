#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> par;
vector<int> ans;

void dfs(int nn, int pp, int depth)
{
    par[nn] = pp;
    ans[nn] = depth;
    for(auto neigh:g[nn])
    {
        if(neigh!=pp)
        {
            dfs(neigh,nn,depth+1);
        }
    }
}

int FindNumManagers(int n, vector<vector<int>> edges)
{
    g.resize(n+1);
    par.assign(n+1,-1);
    ans.assign(n,1);

    for(int i=0;i<n-1;i++)
    {
        int man = edges[i][0];
        int empl = edges[i][1];
        g[man].push_back(empl);
        g[empl].push_back(man);
    }
    dfs(0,-1,1);
    int val = 0; 
    for(int i=0;i<n;i++)
    {
        if(g[i].size()==1)
        {
            ans[i] = 1;
        }
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin>>n;
    vector<vector<int>> edges(n,vector<int>(2));
    for(int i=0;i<n-1;i++)
    {
        cin>>edges[i][0]>>edges[i][1];
    }
    int res = FindNumManagers(n,edges);
    cout<<res<<'\n';
}