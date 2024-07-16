//https://atcoder.jp/contests/dp/tasks/dp_s
//L = 1
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int n,d,mod = 1e9 + 7;
string l,r;
int dp[10001][2][2][101];

lli rec(int level,int Ltight, int Htight, int sumD)
{
    if(level==n){
        if(sumD==0) return 1;
        else return 0;
    }
    if(dp[level][Ltight][Htight][sumD]!=-1) return dp[level][Ltight][Htight][sumD];

    lli ans = 0, lo = 0, hi = 9;
    if(Ltight) lo = l[level]-'0';
    if(Htight) hi = r[level]-'0';

    for(int i=lo;i<=hi;i++)
    {
        int nLti = Ltight, nHti = Htight;

        if(i!=l[level]-'0') nLti = 0;
        if(i!=r[level]-'0') nHti = 0;

        ans += rec(level+1,nLti,nHti,(sumD+i)%d);
        ans %= mod;
    }
    return dp[level][Ltight][Htight][sumD] = ans%mod;
}

void solve()
{
    //cin>>l;
    l = "1";
    cin>>r; cin>>d;
    n = r.size();
    
    //making l and r of the same length by padding '0's
    int diff = r.size() - l.size();
    string pre = "";
    for(int i=0;i<diff;i++){
        pre.push_back('0');
    }
    l = pre + l;

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}