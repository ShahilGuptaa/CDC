//create a DS, that support
//+X, -X: insertion and deletion of X
//? Y K: find the number of X in the DS, s.t, (X^Y) <= K

#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<lli,lli>;

struct node{
    node* child[2];
    lli cnt;
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
    void insert(int n){
        node *cur = root;
        for(int i=31;i>=0;i--)
        {
            cur->cnt++;
            int x = (n&(1ll<<i)) ? 1 : 0;
            if(cur->child[x]==NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->cnt++;
    }
    void del(int n){
        node *cur = root;
        for(int i=31;i>=0;i--)
        {
            cur->cnt--;
            int x = (n&(1ll<<i)) ? 1 : 0;
            cur = cur->child[x];
        }
        cur->cnt--;
    }
    int query(int y,int k){
        node *cur = root;
        int ans = 0;
        for(int i=31;i>=0;i--)
        {
            int b = (y&(1ll<<i)) ? 1 : 0;
            int c = (k&(1ll<<i)) ? 1 : 0;
            if(b==0 && c==0){
                cur = cur->child[0];
            }
            else if(b==1 && c==0){
                cur = cur->child[1];
            }
            else if(b==0 && c==1){
                ans += cur->child[0]->cnt;
                cur = cur->child[1];
            }
            else{
                ans += cur->child[1]->cnt;
                cur = cur->child[0];
            }
        }
        ans += cur->cnt; //this will give count of x, s.t, x^y==k
        return ans;
    }
};

void solve()
{
    lli n;cin>>n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}