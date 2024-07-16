#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int dp[101][1010];

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];

        vector<vector<bool>> dp(n+1,vector<bool>(sum+2));
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int j=1;j<=sum;j++) dp[0][j] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i-1]<=j) dp[i][j] = max(dp[i][j],dp[i-1][j-nums[i-1]]);
            }
        }
        int ans = sum;
        for(int j=0;j<=sum;j++){
            if(dp[n][j]){
                int s1 = j,s2 = sum-j;
                int diff = abs(s1-s2);
                ans = min(ans,diff);
            }
        }
        return ans;
    }
};

void solve()
{
    lli n,tar;cin>>n>>tar;
    vector<int> a(n);
    memset(dp,-1,sizeof(dp)); //[n][tar]

    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    Solution obj;
    cout<<obj.minimumDifference(a)<<'\n';
    
    //Initializing
    for(int i=0;i<=n;i++){
        for(int j=0;j<=tar;j++){
            if(j==0){
                dp[i][j] = 1;
            }
            else if(i==0){
                dp[i][j] = 0;
            }
        }
    }

    //Logix
    for(int i=1;i<=n;i++){
        for(int j=1;j<=tar;j++){
            if(j>=a[i-1]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][tar]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int t;cin>>t;while(t--)
    solve();
}