#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli tree[4*N];
vector<pair<string,int>> v;

bool is_Vowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        return 1;
    }return 0;
}

void build(int node,int st, int en)
{
    if(st==en){
        if(v[st].S==1){
            tree[node] = 1;
        }
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);

    tree[node] = tree[2*node]+tree[2*node+1];
    return;
}

lli query(int node, int st,int en,int l,int r)
{
    if(l>en || r<st){
        return 0;
    }
    if(st>=l && en<=r){
        return tree[node];
    }
    int mid = (st+en)/2;
    return query(2*node,st,mid,l,r) + query(2*node+1,mid+1,en,l,r);
}

void solve()
{
    lli n;cin>>n;
    v.resize(n);

    for(int i=0;i<n;i++) {
        cin>>v[i].F;
        int len = v[i].F.length();
        if(is_Vowel(v[i].F[0]) && is_Vowel(v[i].F[len-1]) )
        {
            v[i].S = 1;
        }
    }
    build(1,0,n-1);

    int q; cin>>q;
    while(q--)
    {
        lli l,r; cin>>l>>r;
        l--; r--;
        cout<<query(1,0,n-1,l,r)<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}