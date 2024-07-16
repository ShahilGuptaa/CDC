#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[502][63000];

lli bin_pow(lli a, lli b, int m) //return (a^b)%m in log(b)
{
    if(b==0) return 1;
    if(b==1)return a%m;
    lli ans = bin_pow(a,b/2,m)%m;
    if(b%2) return ((a%m)*((ans*ans)%m))%m;
    else return (ans*ans)%m;
}

lli rec(vector<int> &a, int n, lli tar){
    if(tar==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][tar]!=-1) return dp[n][tar];

    lli ans = rec(a,n-1,tar)%mod;
    if(a[n-1]<=tar){
        ans += rec(a,n-1,tar-a[n-1]);
        ans%=mod;
    }
    ans%=mod;
    return dp[n][tar] = ans;
}

void solve()
{
    lli n;cin>>n;
    memset(dp,-1,sizeof(dp));

    vector<int> v(n);
    for(int i=0;i<n;i++){
        v[i] = i+1;
    }
    lli sum = n*(n+1)/2;
    if(sum%2){
        cout<<"0\n";
    }else{
        lli tar = sum/2;
        lli ans = rec(v,n,tar);
        ans *= bin_pow(2,mod-2,mod);
        cout<<ans%mod<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}