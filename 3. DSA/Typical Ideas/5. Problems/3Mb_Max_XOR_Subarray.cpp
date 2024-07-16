#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

struct node{
    node *child[2];
    node(){
        child[0] = NULL; child[1] = NULL;
    }
};

struct trie{
    node *root;
    trie(){
        root = new node();
    }
    void insert(int n){
        node *cur = root;
        for(int i=20;i>=0;i--)
        {
            int x = (n&(1<<i))?1:0;
            if(cur->child[x]==NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
    }
    int query(int n)
    {
        node *cur = root;
        int ans = 0;
        for(int i=20;i>=0;i--)
        {
            int x = (n&(1<<i))?1:0;
            if(cur->child[(!x)]!=NULL){
                ans += (1<<i);
                cur = cur->child[(!x)];
            }else{
                cur = cur->child[x];
            }
        }
        return ans;
    }
};

void solve()
{
    int n;cin>>n;
    int pre_xor = 0, ans = 0;
    int x;
    trie t;
    t.insert(0);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        pre_xor ^= x;
        ans = max(ans,x);
        t.insert(pre_xor);
        ans = max(ans,t.query(pre_xor));
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