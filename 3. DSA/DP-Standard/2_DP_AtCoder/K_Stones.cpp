#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli n,k;
vector<lli> a;
lli dp[100100];

//Recursive will give MLE
int rec(lli l){ //will the current player win if there are l stones left for removal

    if(l<=0){
        return 0;
    }
    if(dp[l]!=-1) return dp[l]; 

    int ans = 0;
    for(int i=0;i<n;i++){
        if(a[i]<=l){
            if(rec(l-a[i])==0){
                ans = 1;
                break;
            }
        }
    }
    return dp[l] = ans;
}

void solve()
{
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int s=1;s<=k;s++){
        dp[s] = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=s && dp[s-a[i]]==0){
                dp[s] = 1;
            }
        }
    }
    if(dp[k])cout<<"First\n";
    else cout<<"Second\n";
}

int main()
{
    solve();
}