#include<bits/stdc++.h>
using namespace std;

int n,m;
long long int dp[12][12][(1<<12)];
long long int rec(int i, int j, int mask) //mask will contain 0,1,2,..,m-1 bits
{
    //base case
    if(i==n)
    {
        if(mask+1==(1<<m)) return 1;
        else return 0;
    }
    //memoization
    if(dp[i][j][mask]!=-1) return dp[i][j][mask];

    //transitions
    long long int ans = 0;
    int fbit = (mask&1); //upper is filled or not
    int lbit = (mask&(1<<(m-1))) ? 1 : 0;
    if(i==0)
    {
        if(j==0){
            ans = rec(i + (j+1==m), (j+1)%(m), mask>>1);
        }
        else{
            ans = rec(i + (j+1==m), (j+1)%m, mask>>1);
            if(!lbit) ans += rec(i + (j+1==m), (j+1)%m, ((mask)>>1)|(1<<(m-1))|(1<<(m-2)));
        }
    }
    else
    {
        if(j==0){
            if(!fbit) ans = rec(i + (j+1==m), (j+1)%m, ((mask)>>1)|(1<<(m-1)));
            else ans = rec(i + (j+1==m), (j+1)%(m), mask>>1);
        }
        else
        {
            if(!fbit) ans = rec(i + (j+1==m), (j+1)%m, ((mask)>>1)|(1<<(m-1)));
            else
            {
                ans = rec(i + (j+1==m), (j+1)%m, (mask>>1));
                if(!lbit) ans += rec(i + (j+1==m), (j+1)%m, ((mask)>>1)|(1<<(m-1))|(1<<(m-2)));
            }
        }
    }
    return dp[i][j][mask] = ans;
}

void solve()
{
    cin>>n>>m;
    if(m>n){
        swap(m,n);
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}