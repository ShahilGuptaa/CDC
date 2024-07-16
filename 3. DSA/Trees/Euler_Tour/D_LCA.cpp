#include<bits/stdc++.h>
using namespace std;
//https://www.spoj.com/problems/LCASQ/
using ii = pair<int,int>;
#define F first
#define S second
int t = 0;
vector<vector<int>> g;
vector<ii> lt;
vector<ii> tree;
vector<int> pre;

void dfs(int nn,int pp,int dd){
    lt.push_back({dd,nn});
    pre[nn] = t++;
    for(auto v: g[nn])
    {
        if(v!=pp) {
            dfs(v,nn,dd+1);
            lt.push_back({dd,nn});
            t++;
        }
    }
}
void build(int node,int st,int en){
    if(st==en){
        tree[node] = lt[st];
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);

    tree[node] = min(tree[2*node],tree[2*node+1]);
    return;
}

ii query(int node,int st,int en,int l,int r){
    if(r<st || en<l) return {1e7,1e7};

    if(st>=l && en<=r) return tree[node];

    int mid = (st+en)/2;
    return min( query(2*node,st,mid,l,r),query(2*node+1,mid+1,en,l,r) );
}
void solve()
{
    int n;cin>>n;
    g.resize(n+1); pre.resize(n+1);
    for(int i=0;i<n;i++){
        int m; cin>>m;
        for(int j=0;j<m;j++)
        {
            int v; cin>>v;
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }
    dfs(0,-1,0);
    //for(auto i: lt) cout<<i.F<<' '<<i.S<<'\n';

    n = lt.size();
    tree.resize(4*n);
    build(1,0,n-1);

    //doing queries
    int Q; cin>>Q;
    while(Q--)
    {
        int u,v; cin>>u>>v;
        int l = pre[u], r = pre[v];
        //cout<<l<<' '<<r<<'\n';
        if(l>r) swap(l,r);
        ii ans = query(1,0,n-1,l,r);
        cout<<ans.S<<'\n';
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}