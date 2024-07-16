#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second

lli n;
vector<lli> a;
vector<vector<lli>> dp;

//  O(N^2 * 2^(2N))
lli rec(lli board, lli mask) //mask tells which all players are taken
{
    if(board==n) return 0;
    if(mask+1==(1<<(2*n))) return 0;

    if(dp[board][mask]!=-1) return dp[board][mask];

    lli ans = 0, ind = -1;
    for(int i=0;i<2*n;i++){
        if( (mask&(1<<i))==0 ){
            ind = i;
            break;
        }
    } //ind is the first unset bit

    for(int j=ind+1;j<2*n;j++){
        if( (mask&(1<<j))==0 )
        {
            lli happy = abs(a[ind]-a[j])*__gcd(a[ind],a[j]);
            lli temp = ((1<<ind)|(1<<j));
            ans = max(ans,happy + rec(board+1, (mask|temp) ));
        }
    }
    return dp[board][mask] = ans;
}

void solve()
{
    cin>>n;
    a.resize(2*n);
    dp.assign(n,vector<lli>((1<<(2*n)),-1));
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    cout<<rec(0,0)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}