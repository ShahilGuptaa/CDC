#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

//Find MEX of all the prefix arrays

void solve()
{
    lli n; cin>>n;
    vector<lli> arr(n);
    multiset<lli> ms;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ms.insert(i);
    }
    ms.insert(n);

    for(auto v: arr)
    {
        if(ms.find(v)!=ms.end()) ms.erase(v);
        cout<<*ms.begin()<<' ';
    }cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}