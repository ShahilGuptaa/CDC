#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

int n,k;
vector<lli> a;
lli dp[102][100100];
lli pre[102][100100];

//Optimize using prefix sum
lli rec(int n, lli left)
{
    if(left==0){
        return 1;
    }
    if(n==0) return 0;
    //cache check
    if(dp[n][left]!=-1) return dp[n][left];

    lli ans = 0;
    for(int i=0;i<=min(a[n-1],left);i++){
        ans += rec(n-1,left-i)%mod;
    }
    return dp[n][left] = ans;
}

void solve()
{
    cin>>n>>k; a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(i==0) {
                dp[i][j] = 0; pre[i][j] = 1;
            }
            if(j==0) {
                dp[i][j] = 1; pre[i][j] = 1;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            //calculating dp[i][j]
            // for(int g=0;g<=min(j*1ll,a[i-1]);g++)
            //{
            //     dp[i][j] += dp[i-1][j-g]; //prefix sum of (i-1)th row from max(j-a[i-1],0) to j
            // }

            lli ll = max(j-a[i-1],0ll), uu = j;
            
            if(ll==0) dp[i][j] = (pre[i-1][uu]%mod);
            else dp[i][j] = ( (pre[i-1][uu]%mod) - (pre[i-1][ll-1]%mod) + mod)%mod;

            pre[i][j] = ( (pre[i][j-1]%mod) + (dp[i][j]%mod) )%mod;
        }
    }
    cout<<(dp[n][k]+mod)%mod<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}