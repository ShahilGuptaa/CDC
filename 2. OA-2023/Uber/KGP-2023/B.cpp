#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int arr[N];
int tree[4*N];

void build(int node,int st, int en){
    if(st==en){
        if(arr[st]==0) tree[node] = st;
        else tree[node] = mod;
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);

    tree[node] = min(tree[2*node],tree[2*node+1]);
    return;
}

void update1(int node,int st,int en,int ind)
{
    if(st==en)
    {
        if(tree[node]==mod)
        {
            arr[ind] = 0;
            tree[node] = ind;
        }else{
            arr[ind] = 1;
            tree[node] = mod;
        }
        return;
    }
    int mid = (st+en)/2;
    if(ind<=mid) update1(2*node,st,mid,ind);
    else update1(2*node+1,mid+1,en,ind);

    tree[node] = min(tree[2*node],tree[2*node+1]);
    return;
}

void update2(int node,int st,int en,int ind){
    if(st==en){
        arr[ind] = 0;
        tree[node] = ind;
        return;
    }
    int mid = (st+en)/2;
    if(ind<=mid) update2(2*node,st,mid,ind);
    else update2(2*node+1,mid+1,en,ind);

    tree[node] = min(tree[2*node],tree[2*node+1]);
    return;
}

string solve(vector<int> state, vector<string> operations)
{
    int n = state.size();
    for(int i=0;i<n;i++)
    {
        arr[i] = state[i];
    }
    build(1,0,n-1);
    int ops = operations.size();
    for(int i=0;i<ops;i++)
    {
        string p = operations[i];
        if(p[0]=='L'){
            int ind = tree[1];
            if(ind>=n){
                continue;
            }
            update1(1,0,n-1,ind);
        }
        else
        {
            string temp;
            for(int i=1;i<p.size();i++)
            {
                temp += p[i];
            }
            int ind = stoi(temp);
            update2(1,0,n-1,ind);
        }
    }
    string ans;
    for(int i=0;i<n;i++)
    {
        ans.push_back(arr[i]+'0');
    }return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int t; cin>>t;
    vector<string> ops(t);
    for(int i=0;i<t;i++)
    {
        cin>>ops[i];
    }
    cout<<solve(a,ops)<<'\n';
}