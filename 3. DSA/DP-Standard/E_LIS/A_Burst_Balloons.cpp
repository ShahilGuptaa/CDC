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

int rec(int l,int r, vector<int> &a,vector<vector<int>> &dp){
    if(l>r) return 0;
    if(r-l+1==0) return 0;

    if(dp[l][r]!=-1) return dp[l][r];

    int ans = 0;
    for(int i=l;i<=r;i++){
        int le,ri8;
        if(l-1<0) le = 1;
        else le = a[l-1];

        if(r+1>=a.size()) ri8 = 1;
        else ri8 = a[r+1];

        ans = max(ans,a[i]*le*ri8 + rec(l,i-1,a,dp) + rec(i+1,r,a,dp) );
    }
    return dp[l][r] = ans;

}
void solve()
{
    lli n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    cout<<rec(0,n-1,a,dp)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}