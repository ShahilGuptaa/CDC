#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[1010][1010]; //[n][len]
void solve()
{
    lli n;cin>>n;
    lli len; cin>>len;

    vector<int> price(n); //price[i] = price of rod of lenght (i+1)
    vector<int> lenght(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
        lenght[i] = i+1;
    }
    memset(dp,-1,sizeof(dp));
    //Now this is unbounded knapsack with len as capacity
    for(int i=0;i<=n;i++){
        for(int j=0;j<=len;j++){
            if(i*j==0) dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=len;j++){
            dp[i][j] = dp[i-1][j];
            if(lenght[i-1]<=j)
            {
                dp[i][j] = max(dp[i][j],price[i-1] + dp[i][j-lenght[i-1]]);
            }
        }
    }
    cout<<dp[n][len]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}