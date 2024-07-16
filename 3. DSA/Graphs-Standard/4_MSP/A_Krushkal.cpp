#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli mod = 1000000007;

struct union_find{
    int par[100100];
    int rank[100100];
    void init(){
        for(int i=1;i<=100000;i++)
        {
            par[i] = i;
            rank[i]= 0;
        }
    }
    int find(int x)
    {
        if(par[x]==x) return x;
        else return (par[x] = find(par[x])); //path compression
    }

    //rank compression
    void unite(int x,int y){ //merge sety into setx
        int rootx = find(x);
        int rooty = find(y);
        if(rank[rootx]<rank[rooty]) swap(rootx,rooty);
        if(rank[rootx]==rank[rooty]) rank[rootx]++;

        par[rooty] = rootx;
    }
};

vector<vector<ii>> g; //For krushkal we dont even need to create the graph
// we only need sorted edge list
lli n,m;

void solve()
{
    cin>>n>>m;
    //g.resize(n+1);
    vector<pair<int,ii>> edgeList; //weight, {u,v}
    union_find uf;
    uf.init();

    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        // g[u].push_back({w,v});
        // g[v].push_back({w,u});
        edgeList.push_back({w,{u,v}});
    }
    sort(edgeList.begin(),edgeList.end());

    lli mst_cost = 0;
    vector<pair<int,ii>> edgesUsed;
    for(auto edge :edgeList)
    {
        int u = edge.S.F;
        int v= edge.S.S;
        int wt = edge.F;
        if(uf.find(u)!=uf.find(v))
        {
            edgesUsed.push_back(edge);
            mst_cost += wt;
            uf.unite(u,v);
        }
    }
    if(edgesUsed.size()==n-1)
    {
        cout<<mst_cost<<'\n';
    }else{
        cout<<"MST not possible/Graph not connected\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}