#include<bits/stdc++.h>
using namespace std;

long long dp[5005][5005];

long long rec(long long l, long long r, vector<long long> &a){

    if(l==r){
        return dp[l][r]= a[l];
    }
    if(dp[l][r]!=-1) return dp[l][r];

    long long ans = 0;
    ans = max(a[l]-rec(l+1,r,a),a[r]-rec(l,r-1,a));

    return dp[l][r] = ans;
}

void solve()
{
    long long n;cin>>n;
    vector<long long> a(n);
    long long int sum = 0;

    memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }

    long long int diff = rec(0,n-1,a);
    cout<<(diff+sum)/2<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}