#include<bits/stdc++.h>
using namespace std;
//https://cses.fi/problemset/task/1138
vector<vector<int>> g;
vector<int> val,pre,post,lt;
vector<long long int> tree;
int t = 1;
void dfs(int nn,int pp)
{
    pre[nn] = t;
    lt[t++] = val[nn];
    for(auto v: g[nn])
    {
        if(v!=pp) dfs(v,nn);
    }
    post[nn] = t;
    lt[t++] = -1*val[nn];
}
void build(int node,int st,int en){
    if(st==en){
        tree[node] = lt[st];
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid); 
    build(2*node+1,mid+1,en);
 
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}
void update(int node,int st,int en,int ind,int val){
    if(st==en)
    {
        tree[node] = val;
        lt[st] = val;
        return;
    }
    int mid = (st+en)/2;
    if(ind<=mid) update(2*node,st,mid,ind,val);
    else update(2*node+1,mid+1,en,ind,val);
 
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}
long long int query(int node,int st,int en,int l,int r)
{
    if(r<st || en<l ){
        return 0;
    }
    if(st>=l && en<=r) return tree[node];
 
    int mid= (st+en)/2;
    return (query(2*node,st,mid,l,r) + query(2*node+1,mid+1,en,l,r));
}
void solve()
{
    int n,q;cin>>n>>q;
    g.resize(n+1); val.resize(n+1); 
    pre.resize(n+1); post.resize(n+1);
    lt.resize(2*n+1);
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1,0);
    n = lt.size();
    tree.resize(4*n);
    build(1,1,n);
    while(q--)
    {
        int t,node,val;
        cin>>t>>node;
        if(t==1){
            cin>>val;
            int l = pre[node], r = post[node];
            update(1,1,n,l,val);
            update(1,1,n,r,-val);
        }else{
            int l = pre[1], r = pre[node];
            cout<<query(1,1,n,l,r)<<'\n';
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}