#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
lli n,m,p;
vector<lli> v;

void solve()
{
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>m;
    sort(v.begin(),v.end());
    lli ind = n-m;
    if(n==m){
        cout<<"1\n";
        return;
    }else{
        lli prev = n-m-1;
        if(v[prev]==v[ind])
        {
            cout<<"-1\n";
        }
        else{
            cout<<v[prev]+1<<'\n';
        }
    }
}

int main()
{
    solve();
}