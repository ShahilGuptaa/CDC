#include<bits/stdc++.h>
using namespace std;

int dp[1000010];
const int mod = 1000000009;

vector<int> ops(int n){
    vector<int> res;
    while(n>0){
        int l = n%10;
        if(l) res.push_back(l);
        n/=10;
    }
    return res;
}

void solve()
{
    int n;cin>>n;
    dp[0] = 0;
    for(int i=1;i<10;i++) dp[i] = 1;

    for(int i=10;i<=n;i++)
    {
        dp[i] = mod;
        vector<int> ty = ops(i);
        for(auto t: ty)
        {
            dp[i] = min(dp[i],1 + dp[i-t]);
        }
    }
    cout<<dp[n]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}