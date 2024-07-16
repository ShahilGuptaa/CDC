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
int dp[100100];

int rec(int i, int n,int k, vector<lli> &h){ //cost to go from ith stone to (n-1)th stone
    if(i==n-1){
        return 0;
    }
    //cache check
    if(dp[i]!=-1) return dp[i];

    //transitions
    lli ans = INF;
    for(int j=1;j<=k;j++){
        if(i+j<n){
            ans = min(ans, abs(h[i]-h[i+j]) + rec(i+j,n,k,h));
        }
    }
    return dp[i] = ans;
}

void solve()
{
    lli n,k=2;cin>>n;
    vector<lli> h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<=n;i++) dp[i] = -1;
    cout<<rec(0,n,k,h)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}