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
vector<vector<int>> g;
vector<vector<lli>> dp;
lli edges[21][21];
lli init = 1;
lli count_cycles(lli nn, lli mask)
{
    
    if(dp[nn][mask]!=-1) return dp[nn][mask];

    lli ans = ( (__builtin_popcountll(mask) > 2) && (edges[nn][init]) ) ? 1 : 0;

    for(auto v: g[nn])
    {
        if(mask&(1<<(v-1))) continue;
        if(v>init) ans += count_cycles(v,mask|(1<<(v-1))); //to prevent multicounting
    }
    return dp[nn][mask] = ans;
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1); 
    memset(edges,0,sizeof(edges));
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        edges[a][b] = edges[b][a] = 1;
    }
    lli ans = 0;
    for(int i=1;i<=n;i++)
    {
        dp.assign(n+1,vector<lli>((1<<20),-1));
        init = i;
        ans += count_cycles(i,(1<<(i-1)));
    }
    cout<<ans/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}

//this does not calculates all the cycles
// vector<int> col,par;
// set<set<int>> cycles;

// void dfs(int nn, int pp)
// {
//     col[nn] = 2;
//     par[nn] = pp; 

//     for(auto v: g[nn])
//     {
//         if(col[v]==1){
//             dfs(v,nn);
//         }
//         else if(col[v]==2) //back_edge
//         {
//             int temp = nn;
//             set<int> cy;
//             cy.insert(nn);
//             while(temp!=v)
//             {
//                 temp = par[temp];
//                 cy.insert(temp);
//             }
//             cycles.insert(cy);
//         }
//     }

//     col[nn] = 3;
// }