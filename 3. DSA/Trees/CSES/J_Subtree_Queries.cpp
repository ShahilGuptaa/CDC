#include<bits/stdc++.h>
using namespace std;
 
int t = 1;
vector<vector<int>> g;
vector<int> a,pre,post,lt;
vector<long long int> tree;
 
void dfs(int nn, int pp){
    pre[nn] = t;
    lt[t++] = a[nn];
    for(auto v:g[nn]){
        if(v!=pp) dfs(v,nn);
    }
    post[nn] = t;
    lt[t++] = a[nn];
}
 
void build(int node, int l,int r)
{
    if(l==r) {
        tree[node] = lt[l];
        return;
    }
    int mid = (l+r)/2;
 
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
 
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}
 
void update(int ind,int node,int l,int r,int nval){
    if(l==r){
        lt[ind] = nval; tree[node] = nval;
        return;
    }
    int mid= (l+r)/2;
    if(ind<=mid) update(ind,2*node,l,mid,nval);
    else update(ind,2*node+1,mid+1,r,nval);
 
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}
 
long long int query(int node,int st,int en,int l,int r)
{
    if(r<st || en<l) return 0;
 
    if(st>=l && en<=r) return tree[node];
 
    int mid = (st+en)/2;
    return query(2*node,st,mid,l,r) + query(2*node+1,mid+1,en,l,r);
}
 
void solve()
{
    int n,q;cin>>n>>q;
    g.resize(n+1); a.resize(n+1); pre.resize(n+1); post.resize(n+1);
    lt.resize(2*n+1); tree.resize(6*n);
 
    for(int i=1;i<=n;i++) cin>>a[i];
 
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    build(1,1,2*n);
    while(q--)
    {
        int type,s,x; cin>>type>>s;
        if(type==1){
            cin>>x;
            int ind1 = pre[s], ind2 = post[s];
            update(ind1,1,1,2*n,x);
            update(ind2,1,1,2*n,x);
        }else{
            int l = pre[s], r = post[s];
            //find sum of range (l,r) in the lt array
            long long int ans = query(1,1,2*n,l,r);
            cout<<ans/2<<'\n';
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
