#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int n;
int happy[15][15];
long long int happy_sm[(1<<15)]; //just an oprimization
long long int dp[(1<<15)];

long long int happy_grp(int submask)
{
    long long int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int si = (submask&(1<<i)) ? 1 : 0;
            int sj = (submask&(1<<j)) ? 1 : 0;
            if(si && sj){
                ans += happy[i][j];
            }
        }
    }
    return ans;
}

//no. of states = o(2^N)
//no. of transitions = O(submask)
//Time Complexity = O(3^N)
long long int maxHappiness(int mask)
{
    if(mask==0) return 0;

    if(dp[mask]!=-1) return dp[mask];

    long long int ans = 0;
    for(int submask = mask;submask;submask = (submask-1)&mask)
    {
        ans = max(ans,happy_sm[submask] + maxHappiness(mask^submask));
    }
    return dp[mask] = ans;
}

void solve()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>happy[i][j];
        }
    }
    int mask = (1<<n)-1;
    for(int submask = 0; submask < (1<<n); submask++)
    {
        happy_sm[submask] = happy_grp(submask);
    }
    cout<<maxHappiness(mask)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}