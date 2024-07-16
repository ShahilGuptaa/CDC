#include<bits/stdc++.h>
using namespace std;

int n,m;
int mod = 1e9+7;
long long int dp[1001][12][(1<<12)];
long long int rec(int i, int j, int mask) //mask will contain 0,1,2,..,m-1 bits
{
    //base case
    if(i==n)
    {
        if(mask+1==(1<<m)) return 1;
        else return 0;
    }
    //memoization
    if(dp[i][j][mask]!=-1) return dp[i][j][mask]%mod;

    //transitions
    long long int ans = 0;
    int fbit = (mask&1); //upper is filled or not
    int lbit = (mask&(1<<(m-1))) ? 1 : 0;
    if(i==0)
    {
        if(j==0){
            ans = rec(i + (j+1==m), (j+1)%(m), mask>>1)%mod;
        }
        else{
            ans = rec(i + (j+1==m), (j+1)%m, mask>>1)%mod;
            if(!lbit) ans += rec(i + (j+1==m), (j+1)%m, ((mask)>>1)|(1<<(m-1))|(1<<(m-2)))%mod;
        }
    }
    else
    {
        if(j==0){
            if(!fbit) ans = rec(i + (j+1==m), (j+1)%m, ((mask)>>1)|(1<<(m-1)))%mod;
            else ans = rec(i + (j+1==m), (j+1)%(m), mask>>1)%mod;
        }
        else
        {
            if(!fbit) ans = rec(i + (j+1==m), (j+1)%m, ((mask)>>1)|(1<<(m-1)))%mod;
            else
            {
                ans = rec(i + (j+1==m), (j+1)%m, (mask>>1))%mod;
                if(!lbit) ans += rec(i + (j+1==m), (j+1)%m, ((mask)>>1)|(1<<(m-1))|(1<<(m-2)))%mod;
            }
        }
    }
    return dp[i][j][mask] = ans%mod;
}

void solve()
{
    cin>>n>>m;
    if(m>n){
        swap(m,n);
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)%mod<<'\n';
}

int main()
{
    solve();
}