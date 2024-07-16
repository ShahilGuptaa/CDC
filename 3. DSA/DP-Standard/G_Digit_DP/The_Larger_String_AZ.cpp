#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

const lli mod = 1000000007;
int n; string l;
lli dp[100100][2][2];
lli cnt(int level,int t1, int t2)
{
    if(level==n){ //last we will assign number greater than l[n-1]
        if(t1==0 && t2==0) return 1;
        else return 0;
    }
    if(dp[level][t1][t2]!=-1) return dp[level][t1][t2];

    int lo = 'A', hi = 'Z';
    if(t1) lo = l[level];

    lli ans = 0;
    for(int i=lo;i<=hi;i++)
    {
        int nt1 = t1;
        if(i!=lo) nt1 = 0;

        int nt2;
        if(i<l[level]) nt2 = 1;
        else if(i==l[level]) nt2 = t2;
        else nt2 = 0;

        ans += cnt(level+1,nt1,nt2);
        ans%=mod;
    }
    return dp[level][t1][t2] = ans;
}

void solve()
{
    cin>>l;
    n = l.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    cout<<cnt(0,1,1)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}