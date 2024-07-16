#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int n,m; //n<=20
vector<vector<lli>> g,dp;

//O( (N+M) * (1<<N) )
//Hamiltonian graph problems cannot be solved in polynomial type
lli ways(int nn, int mask)
{
    if(mask+1==(1<<n))
    {
        if(nn==n) return 1;
        else return 0;
    }
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
    cout<<ways(1,1)<<'\n'; //starting from 1 node ans 1 node is already visited
}

int main()
{
    solve();
}