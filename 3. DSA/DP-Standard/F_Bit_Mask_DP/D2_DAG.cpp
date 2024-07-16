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
vector<vector<lli>> g;
vector<lli> dp;
lli edges[21][21];

//pos = #set bits in the mask so we can keep dp[mask], space reduction
lli rec(lli pos, lli mask) 
{
    if(pos==n) return 0;

    if(dp[mask]!=-1) return dp[mask];

    lli ans = 10000; 
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
    return dp[mask] = ans;
}

void solve()
{
    cin>>n;
    g.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>edges[i][j];
            if(edges[i][j]) g[i].push_back(j);
        }
    }
    lli ans = 10000;
    for(int i=1;i<=n;i++)
    {
        dp.assign(1<<n,-1);
        ans = min(ans,rec(1,(1<<(i-1))));
    }
    cout<<ans<<'\n';
    g.clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}