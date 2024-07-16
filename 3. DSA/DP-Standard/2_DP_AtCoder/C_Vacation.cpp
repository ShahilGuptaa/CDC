#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

vector<vector<lli>> dp;
int n;
vector<lli> a,b,c;
lli rec(int level, int last){ //return max happiness in [level,n-1]
    if(level==n){
        return 0;
    }
    if(dp[level][last]!=-1) return dp[level][last];

    lli ans = 0;
    for(int i=0;i<3;i++){
        if(i!=last){
            if(i==0) ans = max(ans,a[level] + rec(level+1,i));
            if(i==1) ans = max(ans,b[level] + rec(level+1,i));
            if(i==2) ans = max(ans,c[level] + rec(level+1,i));
        }
    }
    return dp[level][last] = ans;
}
void solve()
{
    cin>>n;
    a.assign(n,0); b.assign(n,0); c.assign(n,0);
    dp.assign(n+2,vector<lli>(4,-1));

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    lli ans = max({a[0] + rec(1,0),b[0] + rec(1,1),c[0] + rec(1,2)});
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}