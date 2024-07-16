#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
#define F first
#define S second
const lli mod = 1000000007;

void solve()
{
    lli n,m;cin>>n>>m;
    vector<ii> v; //red,blue
    v.assign(n+1,{0,n-1});

    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        v[a].F++;
        v[a].S--;

        v[b].F++;
        v[b].S--;
    }

    lli p=0;
    for(int i=1;i<=n;i++)
    {
        p += v[i].F*(v[i].F-1)/2 + v[i].S*(v[i].S-1)/2;
    }

    lli ans = p - (n*(n-1)*(n-2))/6;
    cout<<(ans/2)%mod<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}