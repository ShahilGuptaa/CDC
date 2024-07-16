#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.first!=b.first)return a.first<b.first;

    return a.second>b.second;
}
void solve()
{
    int n;cin>>n;
    vector<pair<int,int>> v;
    vector<int> lis;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
        auto idx=lower_bound(lis.begin(),lis.end(),v[i].second);
        if(idx!=lis.end())
        {
            lis[idx-lis.begin()]=v[i].second;
        }
        else
            lis.push_back(v[i].second);
    }
    cout<<lis.size()<<endl;
}

int main()
{
    solve();
}