#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli n;
vector<lli> val;
vector<lli> dp;
lli gcd[20][20]; //this is also an optimization


lli rec(lli level,lli mask) //mask tells players already chosen
{
    if(level==n+1) return 0;
    if(mask+1==(1<<(2*n))) return 0;
    
    if(dp[mask]!=-1) return dp[mask];

    lli ans = 0;
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            lli temp = ((1<<i)|(1<<j));
            if( (mask&temp) == 0 && i!=j) //note the i != j here
            {
                lli happy = (level)*abs(val[i]-val[j])*gcd[i][j] ;
                ans = max(ans,happy + rec(level+1,(mask|temp)));
            }
        }
    }
    return dp[mask] = ans;
}

void solve()
{
    cin>>n;
    val.resize(2*n);
    dp.assign((1<<(2*n)),-1);

    for(int i=0;i<2*n;i++) {
        cin>>val[i];
    }
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++){
            gcd[i][j] = __gcd(val[i],val[j]);
        }
    }
    cout<<rec(1,0)<<'\n';
    val.clear();
}

int main()
{
    int t; cin>>t; while(t--)
    solve();
}