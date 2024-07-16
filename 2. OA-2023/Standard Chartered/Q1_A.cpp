#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

void solve()
{
    lli n;cin>>n;
    multiset<lli> ms;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ms.insert(x);
    }
    int ans = 1;
    while(!ms.empty())
    {
        int temp = 0;
        int st = *ms.begin();
        while(ms.find(st)!=ms.end())
        {
            temp += ms.size();
            ms.erase(st);
            st++;
            temp -= ms.size();
        }
        ans = max(ans,temp);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}