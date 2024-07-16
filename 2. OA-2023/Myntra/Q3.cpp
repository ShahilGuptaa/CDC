#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int dp[105][1005];
const int mod = 1000000007;

int rec(int level,int sum)
{
    if(level==n)
    {
        if(sum==0)return 1;
        return 0;
    }
    if(dp[level][sum]!=-1) return dp[level][sum];
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        if(sum-i>=0)
        ans+=rec(level+1,sum-i);
        ans%=mod;
    }
    return dp[level][sum]=ans;
}

void solve()
{
    int s;
    cin>>m>>n>>s;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,s)<<endl;
}

int32_t main()
{
    solve();
}