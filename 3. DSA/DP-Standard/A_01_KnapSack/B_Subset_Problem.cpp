#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[1010][1010];

int rec(int n,int tar,vector<int> &a){

    //Base case
    if(tar==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    //Cache check
    if(dp[n][tar]!=-1) return dp[n][tar];

    //transition
    int ans = (rec(n-1,tar,a)|rec(n-1,tar-a[n-1],a));

    //save and return 
    return dp[n][tar] = ans;
}

void solve()
{
    lli n,tar;cin>>n>>tar;
    vector<int> a(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<rec(n,tar,a)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}