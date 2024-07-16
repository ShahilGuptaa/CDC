#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[1010][1010];
void solve()
{
    lli n,diff,sum = 0;cin>>n>>diff;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    int s1,s2; //without any loss of generality we can asssume s1>s2
    //s1 - s2 = diff;
    //s1 + s2 = sum;
    //s1 = (sum+diff)/2;
    //Now we want to count the number of subsets with target = s1
    s1 = (sum+diff)/2;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(a[i-1]<=j){
                dp[i][j] += dp[i-1][j-a[i-1]];
            }
        }
    }
    cout<<dp[n][s1]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}