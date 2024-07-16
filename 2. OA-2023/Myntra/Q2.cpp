#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 10000;

vector<vector<int>> g;
lli n;
int ans;
vector<vector<lli>> dp;

int dfs(int node,int passes){
    if(passes==n){
        if(node==2 || node==3) return 1;
        return 0;
    }
    if(dp[node][passes]!=-1) return dp[node][passes];
    int ans=0;
    for(int i:g[node]){
        ans+=dfs(i,passes+1);
        ans%=mod;
    }
    return dp[node][passes]=ans%mod;
}

void solve()
{
    ans = 0;
    cin>>n;

    //Directed Graph Created
    dp.assign(12,vector<lli>(n+1,-1));
    g.resize(12);
    for(int i=2;i<=11;i++){
        g[1].push_back(i);
    }
    for(int i=8;i<=11;i++){
        for(int j=2;j<=11;j++){
            if(i!=j)
            {
                g[i].push_back(j);
            }
        }
    }
    for(int i=4;i<=7;i++){
        for(int j=2;j<=7;j++){
            if(i!=j){
                g[i].push_back(j);
            }
        }
    }
    g[2].push_back(3);
    g[3].push_back(2);

    cout<<dfs(1,0)%mod<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}