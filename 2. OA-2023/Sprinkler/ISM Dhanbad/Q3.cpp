#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;

void solve()
{
    lli n,m;cin>>n>>m;
    vector<lli> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    lli b = m/n;
    lli dragons_left = (m%n);
    lli dragons_killed = 0;

    for(int i=0;i<n;i++){
        dragons_killed += b;
        v[i] -= b;
    }
    for(int i=0;i<dragons_left;i++){
        v[i] -= 1;
    }
    set<int> indices;
    for(int i=0;i<n;i++){
        if(v[i]>0){
            indices.insert(i);
        }
    }
    for(int i=0;i<n;i++){
        if(v[i]<0)
        {
            while(v[i]<0)
            {
                int p;
                if(indices.lower_bound(i)!=indices.end()){
                    p = *indices.lower_bound(i);
                }
                else{
                    p = *indices.begin();
                }
                if(v[p]+v[i]>0){
                    v[p] += v[i];
                    v[i] = 0;
                }else{
                    v[i] += v[p];
                    v[p] = 0;
                    indices.erase(p);
                }
            } 

        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<' ';
    }cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}