#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli n,m;
vector<vector<lli>> g;
vector<vector<lli>> dp;

int dfs(int nn, int pp, int gc)
{
    //Memoization
    if(dp[nn][gc]!=-1) return dp[nn][gc];

    int ans = 0;
    //Base Case
    if(g[nn].size()==1) //only parent is there, so leaf node
    {
        for(int col=1;col<=m;col++){
            if(__gcd(gc,col)==1) ans++;
        }
        return dp[nn][gc] = ans;
    }

    for(int col = 1; col<=m; col++)
    { 
        int temp = 1;
        for(auto v: g[nn]){
            if(v!=pp)
            {
                int ans_child = dfs(v,nn,__gcd(gc,col));
                temp *= ans_child;
                temp%=mod;
            }
        }
        ans += temp;
        ans %= mod;
    }
    return dp[nn][gc] = ans;
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    dp.assign(n+1,vector<lli>(21,-1));
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