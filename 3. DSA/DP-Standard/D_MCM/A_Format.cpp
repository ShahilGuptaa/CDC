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
int solve(vector<int> &a, int i, int j)
{
    //base case
    if(i>j) return 0;

    // Cache check
    if(dp[i][j]!=-1) return dp[i][j];

    //transitions
    int ans=0;
    for(int k=i;k<j;k++){
        ans = min(ans,solve(a,i,k)+solve(a,k+1,j));
    }

    //save and return
    return dp[i][j]=ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

}