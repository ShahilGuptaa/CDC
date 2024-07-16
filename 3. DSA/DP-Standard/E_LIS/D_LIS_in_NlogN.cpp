// https://www.youtube.com/watch?v=nf3YG4CnTbg

#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;


void solve()
{
    lli n;cin>>n;
    vector<lli> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<lli> lasts;
    for(int i=0;i<n;i++){
        auto it = lower_bound(lasts.begin(),lasts.end(),v[i]);
        if(it==lasts.end()){
            lasts.push_back(v[i]);
        }else{
            lasts[it-lasts.begin()] = v[i];
        }
    }
    cout<<lasts.size()<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}