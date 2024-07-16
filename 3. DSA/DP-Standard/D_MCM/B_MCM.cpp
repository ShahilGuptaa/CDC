#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli dp[502][502];

lli rec(vector<lli> &a,int i,int j)
{
    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    lli ans = INF;
    for(int k=i;k<j;k++){
        ans = min(ans,rec(a,i,k) + rec(a,k+1,j) + a[i-1]*a[k]*a[j]); 
        //adding cost of merging = a[i-1]*a[k]*a[j]
    }
    return dp[i][j] = ans;
}

void solve()
{
    lli n;cin>>n;
    vector<lli> a(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(i>0){
            cout<<"Matrix "<<i<<": "<<a[i-1]<<' '<<a[i]<<'\n';
        }
    }
    cout<<rec(a,1,n-1)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}