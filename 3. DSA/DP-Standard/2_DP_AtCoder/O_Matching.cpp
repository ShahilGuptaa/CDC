#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

lli n;
vector<vector<int>> com;
lli dp[22][2100000];

lli rec(int m,lli bitmask){
    if(m==0)
    {
        for(int i=0;i<n;i++){
            if( ((bitmask>>i)&1) && com[m][i]){
                return 1;
            }
        }
        return 0;
    }
    if(dp[m][bitmask]!=-1) return dp[m][bitmask];

    lli ans = 0;
    for(int i=0;i<n;i++)
    {
        if( ((bitmask>>i)&1) && com[m][i])
        {
            lli mask = (1ll<<i);
            ans += rec(m-1,(bitmask^mask))%mod;
        }
    }
    return dp[m][bitmask] = ans%mod;
}

void solve()
{
    cin>>n;
    com.resize(n+1,vector<int>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>com[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    lli mask = (1ll<<21)-1;
    cout<<rec(n-1,mask)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}