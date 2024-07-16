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
    map<lli,lli> mp;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mp[v[i]]++;
    }
    ii ans = *mp.begin();
    for(auto it:mp){
        if(it.second > ans.second){
            ans = it;
        }
    }
    sort(v.begin(),v.end());
    int ops = 0;
    int x = ans.first; 
    for(int i=0;i<n;i++)
    {
        if(v[i]==x) continue;

        while(v[i]!=x)
        {
            ops++;
            int l = ceil((float)v[i]*0.5);
            int r = v[i]*2;
            if(x>=l && x<=r)
            {
                break;                
            }
            if(v[i]<x) v[i]*=2;
            else v[i] = ceil((float)v[i]*0.5);
        }
        cout<<'\n';
    }
    cout<<ops<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}