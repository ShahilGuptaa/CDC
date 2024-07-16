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
lli edges[21][21];

lli rec(lli pos, lli mask)
{
    if(pos==n) return 0;

    if(dp[pos][mask]!=-1) return dp[pos][mask];

    lli ans = m; 
    for(int i=1;i<=n;i++) //finding bits not set in mask
    {
        if(mask&(1<<(i-1))) continue;

        //ith node is inserted
        lli temp = 0;
        for(int j=1;j<=n;j++)
        {
            if(mask&(1<<(j-1))){
                temp += edges[i][j];
            }
        }
        ans = min(ans,temp + rec(pos+1,mask|(1<<(i-1))));
    }
    return dp[pos][mask] = ans;
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    
    memset(edges,0,sizeof(edges));
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        edges[u][v] = 1;
    }
    lli ans = m;
    for(int i=1;i<=n;i++)
    {
        dp.assign(n,vector<lli>((1<<n),-1));
        ans = min(ans,rec(1,(1<<(i-1))));
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}