#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
#define F first
#define S second
vector<vector<ii>> g;
vector<vector<int>> par;
vector<long long int> prefix;
vector<int> depth;
map<ii,int> weight;

//prefix[node] = distance to get to that node from root, i.e, 1
//note prefix will work only if the the operation is sum or xor
//for other types of queries use the previous approach only

void dfs(int nn, int pp, int dd)
{
    par[nn][0] = pp;
    depth[nn] = dd;
    prefix[nn] = prefix[pp] + weight[{nn,pp}];

    for(int i=1;i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
    }

    for(auto v: g[nn]){
        if(v.F!=pp){
            dfs(v.F,nn,dd+1);
        }
    }
}

long long int path_sum(int u, int v)
{
    int temp1 = u, temp2 = v;
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--)
    {
        if((diff&(1<<i)))
        {
            u = par[u][i];
        }
    }
    if(u==v){ //u is the lca
        return prefix[temp1] - prefix[u];
    } 

    for(int i=19;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    int lca = par[u][0];
    return prefix[temp1] + prefix[temp2] - 2*prefix[lca];
}


void solve()
{
    int n;cin>>n;
    g.resize(n+1); depth.assign(n+1,0);
    prefix.assign(n+1,0);
    par.assign(n+1,vector<int>(20,0));

    for(int i=0;i<n-1;i++)
    {
        int u,v,wt; cin>>u>>v>>wt;
        weight[{u,v}] = wt;
        weight[{v,u}] = wt;
        
        g[u].push_back({v,wt}); g[v].push_back({u,wt});
    }
    weight[{1,0}] = 0;
    dfs(1,0,0);

    int q; cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<path_sum(u,v)<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}