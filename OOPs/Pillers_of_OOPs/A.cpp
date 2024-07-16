#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

lli n,b;
vector<lli> a;
vector<vector<lli>> dp;

lli rec(int l, int sum){ //is it possible to create this sum
    if(sum==0) return 1;
    if(l==n) return 0;

    if(dp[l][sum]!=-1) return dp[l][sum];

    int ans = 0;
    lli diff = sum - (a[l]%b);
    diff%=b;
    diff = (diff%b + b)%b;
    ans = max(rec(l+1,diff), rec(l+1,sum));

    return dp[l][sum] = ans;
}

void solve()
{
    cin>>n>>b;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];

    dp.resize(n+1,vector<lli>(b+1,-1));
    lli ans = 0;
    for(lli i=1;i<b;i++){
        if(rec(0,i)){
            ans = i;
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}