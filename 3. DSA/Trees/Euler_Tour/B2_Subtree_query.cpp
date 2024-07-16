//using eulor tour variation

// https://cses.fi/problemset/task/1137

#include<bits/stdc++.h>
using namespace std;

int t = 0;
vector<vector<int>> g;
vector<int> a,pre,post,lt;
vector<long long int> tree;

void dfs(int nn, int pp){
    pre[nn] = ++t;
    lt[t] = a[nn]; //inserted only once
    for(auto v:g[nn]){
        if(v!=pp) dfs(v,nn);
    }
    post[nn] = t;
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
    lt.resize(n+1); tree.resize(3*n);

    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0); //euler tree is initialized
    build(1,1,n);
    while(q--)
    {
        int type,s,x; cin>>type>>s;
        if(type==1){
            cin>>x;
            int ind = pre[s];
            update(ind,1,1,n,x);
        }else{
            int l = pre[s], r = post[s];
            //find sum of range (l,r) in the lt array
            long long int ans = query(1,1,n,l,r);
            cout<<ans<<'\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}