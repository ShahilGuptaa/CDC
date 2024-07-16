//For hamiltonian path the length is (n-1) for unweighted graph

#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<lli,lli>;
#define F first
#define S second
lli INF = 1e15;

int n,m; //n<=20
vector<vector<ii>> g;
vector<vector<lli>> dp;
//O( (N+M) * (1<<N) )
//Hamiltonian graph problems cannot be solved in polynomial type
lli shortest(lli nn, lli mask) 
{
    //if we want to get shortest for any hamiltonian path from i, we can just change this base case
    if(mask+1==(1<<n)) 
    {
        //return 0 always if last node is not restructed to node n
        if(nn==n) return 0;
        else return INF;
    }
    if(dp[nn][mask]!=-1) return dp[nn][mask];

    lli ans = INF;
    for(auto v: g[nn])
    {
        if(mask&(1<<(v.F-1))) continue;
        ans = min(ans , v.S + shortest( v.F, (mask|(1<<(v.F-1))) ) );
    }
    return dp[nn][mask] = ans;
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    dp.assign(n+1,vector<lli>((1<<n)+5,-1));
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w; 
        g[u].push_back({v,w});
    }
    cout<<shortest(1,1)<<'\n'; //starting from 1 node ans 1 node is already visited
}

int main()
{
    solve();
}