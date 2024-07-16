#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

vector<vector<lli>> g;
vector<lli> a;
vector<lli> pre,post;
vector<lli> linear_tree;
int t = 0;
void dfs(int nn,int pp)
{
    pre[nn] = t;
    linear_tree[t] = a[nn];
    t++;
    for(auto v:g[nn]){
        if(v!=pp) dfs(v,nn);
    }
    post[nn] = t;
    linear_tree[t] = a[nn];
    t++;
}

void solve()
{
    lli n;cin>>n;
    //1 based indexing considered
    g.resize(n+1); a.resize(n+1);
    linear_tree.resize(2*n); //we will start time from t = 0
    pre.resize(n+1); post.resize(n+1);

    for(int i=0;i+1<n;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++) cin>>a[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}