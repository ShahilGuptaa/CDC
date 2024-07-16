#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli bin_pow(lli a, lli b, int m) //return (a^b)%m in log(b)
{
    if(b==0) return 1;
    if(b==1)return a%m;
    lli ans = bin_pow(a,b/2,m)%m;
    if(b%2) return ((a%m)*((ans*ans)%m))%m;
    else return (ans*ans)%m;
}
void solve()
{
    lli n; cin>>n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}