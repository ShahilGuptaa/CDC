#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

//Finding Groups of Anagrams

void solve()
{
    lli n;cin>>n;
    set<string> v;

    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        v.insert(s);
    }

    map<map<char,int>,int> mp;
    for(auto st : v)
    {
        map<char,int> indi;
        for(int i=0;i<st.size();i++)
        {
            indi[st[i]]++; 
        }
        mp[indi]++;
    }
    cout<<mp.size()<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}