#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

void quickSort(int l, int h,vector<lli> &v)
{
    if(l>=h) return;
    int i = l, j = h;
    int pivot = v[l];
    int partition = -1;
    while(i<j)
    {
        while(i<h && v[i]<=pivot){
            i++;
        }
        while(j>l && v[j]>=pivot){
            j--;
        }
        if(i<j) swap(v[i],v[j]);
        else {
            swap(v[l],v[j]);
            partition = j;
        }
    }
    quickSort(l,partition-1,v);
    quickSort(partition+1,h,v);
    return;
}

void solve()
{
    lli n;cin>>n;
    vector<lli> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    quickSort(0,n-1,v);
    for(auto x: v){
        cout<<x<<' ';
    }cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}