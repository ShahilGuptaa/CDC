//find max a[i]^a[j] (i!=j)

#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<lli,lli>;

struct node{
    node *child[2];
    lli cnt ;
    node(){
        cnt = 0;
        child[0] = NULL;
        child[1] = NULL;
    }
};

struct trie{
    node *root;
    trie(){
        root = new node();
    }
    void insert(lli n)
    {
        node *cur = root;
        for(int i=60;i>=0;i--){
            cur->cnt++;
            int x = (n&(1ll<<i)) ? 1: 0;
            if(cur->child[x]==NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->cnt++;
    }
    lli query(lli n)
    {
        node *cur = root;
        lli ans = 0;
        for(int i=60;i>=0;i--)
        {
            int x = (n&(1ll<<i)) ? 1 : 0;
            if(cur->child[(!x)] !=NULL){
                ans += (1ll<<i);
                cur = cur->child[(!x)];
            }
            else{
                cur = cur->child[x];
            }
        }
        return ans;
    }
};

void solve()
{
    lli n;cin>>n;
    vector<lli> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    trie t;
    t.insert(a[0]);
    lli ans = 0;
    for(int i=1;i<n;i++){
        ans = max(ans,t.query(a[i]));
        t.insert(a[i]);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}