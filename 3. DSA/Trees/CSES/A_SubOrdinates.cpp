#include<bits/stdc++.h>
using namespace std;
 
using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli mod = 1000000007;
 
vector<vector<lli>> g;
vector<lli> subtree_sz;
 
void dfs(int nn, int pp)
{
    subtree_sz[nn] = 1;
    for(auto v: g[nn])
    {
        if(v!=pp)
        {
            dfs(v,nn);
            subtree_sz[nn] += subtree_sz[v];
        }
    }
}
 
void solve()
{
    lli n;
    cin>>n;
    g.resize(n+1);
    subtree_sz.resize(n+1);
 
    for(int i=2;i<=n;i++)
    {
        int x; cin>>x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<subtree_sz[i]-1<<' ';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    solve();
}