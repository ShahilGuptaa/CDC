#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;

int n,m;
vector<vector<lli>> happy;
lli dp[52][2000];

//no. of states = (M * 2^N)
//no. of transitions = N
//Time complexity is O( (M *2^N) * n) = 50 * 1024 * 10
lli rec(int i, lli mask) //i = student number, initially mask = 1111.. all ranks are available to be distributed
{
    if(i==m+1) return 0;

    if(mask==0) return 0;
    
    if(dp[i][mask]!=-1) return dp[i][mask];
    
    lli ans = rec(i+1,mask); //with out giving any rank
    for(int j=0;j<n;j++)
    {
        if(mask&(1<<j))
        {
            ans = max(ans, happy[i][j] + rec( i+1,(mask^(1<<j)) ) );
        }
    }
    return dp[i][mask] = ans;
}

void solve()
{
    cin>>n>>m; 
    //n = ranks, and m = no. of students
    happy.assign(m+1,vector<lli>(n+1,0));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=(1<<n);j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>happy[i][j];
        }
    }
    lli mask = (1<<n) - 1;
    cout<<rec(0,mask)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}