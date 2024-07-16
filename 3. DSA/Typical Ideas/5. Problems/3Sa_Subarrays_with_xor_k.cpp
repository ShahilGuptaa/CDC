#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

struct node{
    node *child[2];
    lli cnt = 0;
    node(){
        child[0] = NULL; child[1] = NULL;
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
        for(int i=20;i>=0;i--)
        {
            cur->cnt++;
            int x = (n&(1<<i))?1:0;
            if(cur->child[x]==NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->cnt++;
    }
    lli query(lli n, lli k)
    {
        node *cur = root;
        lli ans = 0;
        for(int i=20;i>=0;i--)
        {
            int pl = (n&(1<<i)) ? 1 : 0;
            int kl = (k&(1<<i)) ? 1 : 0;

            if(cur==NULL) break;

            if(pl==0 && kl==0){
                cur = cur->child[0];
            }
            else if(pl==0 && kl==1){
                if(cur->child[0]) ans += cur->child[0]->cnt;
                cur = cur->child[1];
            }
            else if(pl==1 && kl==0){
                cur = cur->child[1];
            }
            else{
                if(cur->child[1]) ans += cur->child[1]->cnt;
                cur = cur->child[0];
            }
        }
        return ans;
    }
};
void solve()
{
    lli n,k;cin>>n>>k;
    vector<lli> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    trie t; t.insert(0);
    lli pre_xor = 0;
    lli ans = 0;
    for(int i=0;i<n;i++)
    {
        pre_xor^=a[i];
        ans += t.query(pre_xor,k);
        t.insert(pre_xor);
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