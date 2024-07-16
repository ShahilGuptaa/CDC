#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli n;
vector<vector<lli>> g,dp;
vector<lli> val;

lli dfs(int nn, int pp, int taken)
{
    //Memoization
    if(dp[nn][taken]!=-1) return dp[nn][taken];

    //Base Case
    if(g[nn].size()==1) //only parent is there, so leaf node
    {
        if(taken) return 0ll;
        else return max(val[nn],0ll);
    }
    lli ans = 0;
    lli temp1 = 0, temp2 = 0;
    for(auto v: g[nn])
    {
        if(v!=pp){
            temp1 += dfs(v,nn,0); //val[node] not taken
            temp2 += dfs(v,nn,1);
        }
    }
    ans = temp1;
    if(!taken) ans = max(ans,val[nn]+temp2);

    return dp[nn][taken] = ans;
}

void solve()
{
    cin>>n;
    g.resize(n+1); val.resize(n+1);
    dp.assign(n+1,vector<lli>(2,-1));

    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<dfs(1,0,0)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}