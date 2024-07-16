#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int n,m; //n<=20
vector<vector<lli>> g,dp;

lli ways(int nn, int mask) //no. of hamiltonian walks from nn with visited as mask
{
    if(mask+1==(1<<n)) return 1; //as we have reached all node
    
    if(dp[nn][mask]!=-1) return dp[nn][mask];

    lli ans = 0;
    for(auto v: g[nn])
    {
        if(mask&(1<<(v-1))) continue;
        ans += ways( v, (mask|(1<<(v-1))) );
    }
    return dp[nn][mask] = ans;
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    dp.assign(n+1,vector<lli>((1<<n)+5,-1));
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v; 
        g[u].push_back(v);
    }
    lli total_walks = 0;

    //or we can create a hypothetical node 0 and from there we can go to any other node
    for(int i=1;i<=n;i++){
        g[0].push_back(i);
    }
    total_walks = ways(0,0);

    cout<<total_walks<<'\n';
}

int main()
{
    solve();
}