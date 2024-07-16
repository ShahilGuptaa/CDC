#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli bin_pow(lli a, lli b, int m) //return (a^b)%m in log(b)
{
    if(b==0) return 1;
    if(b==1)return a%m;
    lli ans = bin_pow(a,b/2,m)%m;
    if(b%2) return ((a%m)*((ans*ans)%m))%m;
    else return (ans*ans)%m;
}

lli n,c;
vector<lli> wt,val;
vector<vector<lli>> dp;

lli rec(lli n, lli cap){
    if(n==0 || cap<=0){
        return 0;
    }
    //cache check
    if(dp[n][cap]!=-1) return dp[n][cap];

    //transitions
    lli ans = 0;
    ans = rec(n-1,cap);
    if(wt[n-1]<=cap) ans = max(ans,val[n-1] + rec(n-1,cap - wt[n-1]));

    return dp[n][cap] = ans;
}

void solve()
{
    cin>>n>>c;
    dp.assign(n+1,vector<lli>(c+2,-1));
    wt.resize(n); val.resize(n);
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    cout<<rec(n,c)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}