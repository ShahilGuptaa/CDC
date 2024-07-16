#include<bits/stdc++.h>
using namespace std;

int dp[502][502];

// int rec(int a, int b){
//     if(a==b) return 0;

//     if(dp[a][b]!=-1) return dp[a][b];

//     int ans = 1e9;
//     for(int i=1;i<a;i++){
//         ans = min(ans,1 + rec(i,b) + rec(a-i,b));
//     }
//     for(int i=1;i<b;i++){
//         ans = min(ans,1 + rec(a,i) + rec(a,b-i));
//     }
//     return dp[a][b] = ans;
// }

int top_down(int a, int b){
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){

            if(i==j) dp[i][j] = 0;
            else{
                dp[i][j] = 1e8;
                for(int k=1;k<i;k++){
                    dp[i][j] = min(dp[i][j],1+dp[i-k][j] + dp[k][j]);
                }
                for(int k=1;k<j;k++){
                    dp[i][j] = min(dp[i][j],1 + dp[i][j-k] + dp[i][k]);
                }
            }
        }
    }
    return dp[a][b];
}

void solve()
{
    int a,b; cin>>a>>b;
    //memset(dp,-1,sizeof(dp));
    cout<<top_down(a,b)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}