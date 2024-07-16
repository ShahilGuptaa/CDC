#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli dp[61][2][2][2][2];
lli l,r;

//Digit DP but using Binary Format instead of Decimal
lli max_xor(int level,int lt1,int ht1,int lt2,int ht2)
{
    if(level==-1) return 0;

    if(dp[level][lt1][ht1][lt2][ht2]!=-1) return dp[level][lt1][ht1][lt2][ht2];

    int l1 = 0, h1 = 1;
    int l2 = 0, h2 = 1;
    
    int ls = (l&(1ll<<level)) ? 1 : 0;
    int rs = (r&(1ll<<level)) ? 1 : 0;

    if(lt1) l1 = ls;
    if(ht1) h1 = rs;

    if(lt2) l2 = ls;
    if(ht2) h2 = rs;

    lli ans = 0;

    //atmost 4 transitions
    for(int i=l1;i<=h1;i++)
    {
        for(int j=l2;j<=h2;j++)
        {
            int nlt1 = lt1, nlt2 = lt2, nht1 = ht1, nht2 = ht2;
            if(i!=l1) nlt1 = 0;
            if(i!=h1) nht1 = 0;
            if(j!=l2) nlt2 = 0;
            if(j!=h2) nht2 = 0;
            ans = max(ans,(i^j)*(1ll<<level) + max_xor(level-1,nlt1,nht1,nlt2,nht2));
        }
    }
    return dp[level][lt1][ht1][lt2][ht2] = ans;
}

void solve()
{
    cin>>l>>r;
    memset(dp,-1,sizeof(dp));
    cout<<max_xor(60,1,1,1,1)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}