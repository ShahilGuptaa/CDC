#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

int n;
int dp[1001][1001];
int arr[1001];

int rec(int level,int pre_ind) //length of longest increasing subsequence from level to (n-1)
{
    //base_case
    if(level==n+1) return 0;

    //catch
    if(dp[level][pre_ind]!=-1) return dp[level][pre_ind];

    //transitions
    int ans=0;
    if((arr[level]>arr[pre_ind]) )
    {
        ans = max(1+rec(level+1,level),rec(level+1,pre_ind));
    }
    else
    {
        ans = rec(level+1,pre_ind);
    }

    //save and return
    return dp[level][pre_ind] = ans;
}

void printset(int level,int pre_ind)
{
    if(level==n+1) return;

    if( (arr[level]>arr[pre_ind]) ) //take
    {
        if(1+rec(level+1,level)>rec(level+1,pre_ind))
        {
            cout<<arr[level]<<' ';
            printset(level+1,level);
        }
        else
        {
            printset(level+1,pre_ind);
        }
    }
    else
    {
        printset(level+1,pre_ind);
    }
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    arr[0] = -1e9;
    cout<<rec(1,0)<<'\n';
    printset(1,0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}