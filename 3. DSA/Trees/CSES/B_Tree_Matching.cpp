#include<bits/stdc++.h>
using namespace std;

//knapsack DP
vector<vector<int>> g;
int dp[200001][2];

int dfs(int nn, int pp, int taken) //no. of nodes we can take, if the current node is taken ot not
{
    if(dp[nn][taken]!=-1) return dp[nn][taken];

    // if(g[nn].size()==1){ //leaf node
    //     return 0; //Why is this failing??
    // }

    int ans = 0;
    int temp = 0;
    for(auto v: g[nn]){
        if(v!=pp){
            temp += dfs(v,nn,0);
        }
    }
    ans = temp;
    if(!taken)
    {
        for(auto v: g[nn])
        {
            int psbl = temp;
            if(v!=pp){
                psbl += 1 + dfs(v,nn,1) - dfs(v,nn,0);
            }
            ans = max(ans,psbl);
        }
    }
    
    return dp[nn][taken] = ans;
}

void solve()
{
    int n;cin>>n;
    g.resize(n+1);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n-1;i++)
    {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<dfs(1,0,0);   
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}