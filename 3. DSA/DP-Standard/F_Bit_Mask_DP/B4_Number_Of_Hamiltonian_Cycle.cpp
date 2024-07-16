#include<bits/stdc++.h>
using namespace std;


using lli = long long int;
using ii = pair<lli,lli>;

int n,m, init; //n<=20
vector<vector<lli>> g,dp;
map<ii,int> freq;

//Find number of hamiltonian Cycles
lli ways(int nn, int mask) //no. of hamiltonian walks from nn to 0 with visited as mask
{
    if(mask+1==(1<<n)){
        //if there is an edge from current node to initial node, then return 1
        if(freq[{nn,init}]) return 1; //as we have reached all node
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
        freq[{u,v}]++;
        g[u].push_back(v);
    }
    
    lli total_cycles = 0;
    init = 1;
    total_cycles = ways(1,1);
    
    cout<<n*total_cycles<<'\n';
}

int main()
{
    solve();
}