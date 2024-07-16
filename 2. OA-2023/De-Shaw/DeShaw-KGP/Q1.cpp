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
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length();

    map<char,int> mp,temp;
    for(int i=0;i<n;i++){
        mp[s1[i]]++;
        temp[s2[i]]++;
    }
    if(mp==temp){
        int ind = 0;
        for(int i=0;i<n-1;i++)
        {
            if(s2[i]<s2[i+1])
            {
                ind = i;
            }
        }
        swap(s2[ind],s2[ind+1]);
        cout<<s2<<'\n';
        return;
    }

    string fin;
    for(int i=0;i<n;i++)
    {
        auto it = mp.lower_bound(s2[i]);
        if(it!=mp.end())
        {
            fin.push_back(it->first);
        }else{
            it--;
            fin.push_back(it->first);
        }
        if(it->second==1)
        {
            mp.erase(it);
        }
    }
    if(fin>s2)
    {
        cout<<fin<<'\n';
    }
    else
    {
        cout<<"-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}