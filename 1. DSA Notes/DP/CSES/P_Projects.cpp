#include<bits/stdc++.h>
using namespace std;

int n;
long long int dp[200100];
vector< pair<long long int,pair<long long int,long long int>> > a;

long long int rec(int level){ //maximum profit from level to n-1
    if(level==n){
        return 0;
    }
    if(dp[level]!=-1) return dp[level];

    long long int ans = 0;
    long long int l = a[level].first;
    long long int r = a[level].second.first;
    long long int val = a[level].second.second;

    pair<long long int,pair<long long int,long long int>> temp = make_pair(r,make_pair(1e10,1e10));
    long long int nxt = upper_bound(a.begin(),a.end(),temp) - a.begin();
    ans = max(rec(level+1), val + rec(nxt));

    return dp[level] = ans;
}
void solve()
{
    cin>>n;
    memset(dp,-1,sizeof(dp)); 
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second.first>>a[i].second.second;
    }
    sort(a.begin(),a.end());
    cout<<rec(0)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}