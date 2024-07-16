#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
string l,r;
int n,d,m;
int dp[2000][2][2][2000][2];

int rec(int level, int lti, int hti, int sum, int type) //type = 1 means odd else type=0 means even, assuming no leading zeros
{
    if(level==n)
    {
        if(sum==0) return 1;
        else return 0;
    }
    if(dp[level][lti][hti][sum][type]!=-1) return dp[level][lti][hti][sum][type];

    int lo = 0, hi = 9;
    if(lti) lo = l[level]-'0';
    if(hti) hi = r[level]-'0';

    int ans = 0;
    for(int i=lo;i<=hi;i++)
    {
        if(type==1 && i==d) continue;
        if(type==0 && i!=d) continue;

        int nlti = lti, nhti = hti, ntype = type;

        if(type==1) ntype=0;
        else ntype=1;

        if(i!=lo) nlti = 0;
        if(i!=hi) nhti = 0;

        int nsum = (10*sum + i)%m; //note how to take modulo
        ans += rec(level+1,nlti,nhti,nsum,ntype);
        ans%=mod;
    }
    return dp[level][lti][hti][sum][type] = ans;
}

void solve()
{
    cin>>m>>d;
    cin>>l>>r;
    n = r.size();

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0,1)<<'\n'; //starting with odd position
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}