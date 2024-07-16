#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;

struct node{
    node *child[2];
    lli cnt[2];
    node(){
        child[0] = NULL;
        child[1] = NULL;
        cnt[0] = 0; cnt[1] = 0;
    }
};

struct trie{
    node *root;
    trie(){
        root = new node();
    }
    void insert(lli n){
        node *cur = root;
        for(int i=31;i>=0;i--)
        {
            int x = (n&(1ll<<i)) ? 1 : 0;
            cur->cnt[x]++;
            if(cur->child[x]==NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->cnt[0]++;
    }
    void del(lli n){
        node *cur = root;
        for(int i=31;i>=0;i--)
        {
            int x = (n&(1ll<<i))?1:0;
            cur->cnt[x]--;
            cur = cur->child[x];
        }
        cur->cnt[0]--;
    }
    lli query(int n){
        node *cur = root;
        lli ans = 0;
        for(int i=31;i>=0;i--)
        {
            int x = (n&(1ll<<i)) ? 1 : 0;

            if(cur->child[(!x)]!=NULL && cur->cnt[(!x)]>0){
                ans += (1ll<<i);
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
    lli n;cin>>n;
    trie t; t.insert(0);
    while(n--){
        char c; cin>>c;
        lli x; cin>>x;
        if(c=='+') t.insert(x);
        if(c=='-') t.del(x);
        if(c=='?') cout<<t.query(x)<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}