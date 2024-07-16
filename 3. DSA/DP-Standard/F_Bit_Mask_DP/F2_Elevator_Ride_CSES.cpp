#include<bits/stdc++.h>
using namespace std;

int n,x;
int psbl[1<<20];
int w[20];

int sm_p(int mask)
{
    long long int temp = 0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)) temp += w[i];
    }
    return (temp<=x);
}
int dp[(1<<20)];

//TC: O(3^n), will pass for n<=17 in 2 sec, 3^17 = 1.3 x 1e8
int rec(int mask) //best way to deliver the mask people
{
    if(mask==0) return 0;

    if(dp[mask]!=-1) return dp[mask];

    int ans = 20;
    for(int submask = mask; submask; submask = (submask-1)&mask)
    {
        if(psbl[submask]){
            ans = min(ans,1 + rec(mask^submask));
        }
    }
    return dp[mask] = ans;
}
void solve()
{
    cin>>n>>x;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int mask=0;mask<(1<<n);mask++)
    {
        psbl[mask] = sm_p(mask);
    }
    cout<<rec( ((1<<n) - 1) );
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}