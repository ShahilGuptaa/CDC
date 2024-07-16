#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
lli n,W;
lli w[1001];
lli val[1001];
lli dp[101][100001];
lli knapsack(lli level,lli wt_taken)
{
    if(wt_taken>W){
        return -1e9;
    }
    if(level==n){
        return 0;
    }
    if(dp[level][wt_taken]!=-1) return dp[level][wt_taken];
    lli ans = 0;
    ans = max(knapsack(level+1,wt_taken),val[level]+knapsack(level+1,wt_taken+w[level]));
    return dp[level][wt_taken] = ans;
}
void solve(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>w[i]>>val[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(0,0)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}