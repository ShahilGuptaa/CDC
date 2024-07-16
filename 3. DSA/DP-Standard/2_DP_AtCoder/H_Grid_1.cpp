#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli n,m;
vector<vector<char>> grid;
vector<vector<lli>> dp;

bool check(int i, int j){
    if(i>=0 && j>=0 && i<n && j<m && grid[i][j]=='.') return 1;
    else return 0;
}

lli rec(int i, int j){
    if(check(i,j)==0){
        return 0;
    }
    if(i==n-1 && j==m-1) return 1;

    if(dp[i][j]!=-1) return dp[i][j]%mod;

    //transitions
    lli ans = 0;
    if(check(i+1,j)) ans += rec(i+1,j)%mod;
    if(check(i,j+1)) ans += rec(i,j+1)%mod;

    return dp[i][j]=(ans%mod);
}

void solve()
{
    cin>>n>>m;
    grid.resize(n+1,vector<char>(m+1));
    dp.assign(n+1,vector<lli>(m+1,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<rec(0,0)%mod<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}