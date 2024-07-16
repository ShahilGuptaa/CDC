#include<bits/stdc++.h>
using namespace std;

int n;
vector<double> p;
vector<vector<double>> dp;

double rec(int i, int coins) //probability of getting i coins as head if we have coins coins
{
    //base case
    if(coins==0){
        if(i==0) return 1.0;
        else return 0.0;
    }

    //cache check
    if(dp[i][coins]>=0) return dp[i][coins];

    //transitions
    double ans = 0;
    if(i<coins) ans = (1.0 - p[coins-1])*rec(i,coins-1);
    if(i>0) ans += p[coins-1]*rec(i-1,coins-1);

    return dp[i][coins] = ans;
}

void solve()
{
    cin>>n;
    p.resize(n);
    dp.assign(n+1,vector<double>(n+1,-2));

    for(int i=0;i<n;i++) {
        cin>>p[i];
    }
    int req = (n+1)/2;
    double ans = 0;

    for(int i=req;i<=n;i++){
        ans += rec(i,n);
    }
    cout<<setprecision(11)<<ans<<'\n';
}

int main()
{
    solve();
}
