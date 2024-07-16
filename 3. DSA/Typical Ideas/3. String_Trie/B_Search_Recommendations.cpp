#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<lli,lli>;


struct node{
    node *child[26];
    int prefix; //no. of strings inside this subtree
    vector<string> wend; //which all string ends here
    node(){
        prefix = 0;
        for(int i=0;i<26;i++) child[i] = NULL;
    }
};

struct trie{
    node *root;
    trie(){
        root = new node();
    }
    void insert(string s) //O(|S|) both time and memory
    {
        node *cur = root;
        for(int i=0;i<s.size();i++){
            cur->prefix++;
            int x = s[i] - 'a';
            if(cur->child[x]==NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x]; 
        }
        cur->wend.push_back(s);
    }
    void dfs(node *cur,vector<string> &ans,int &k)
    {
        if(ans.size()==k) return;
        if(cur->wend.size()!=0){
            ans.push_back(cur->wend[0]);
        }
        for(int i=0;i<26;i++){
            if(cur->child[i]) dfs(cur->child[i],ans,k);
        }
    }
    void query(string s, int k)
    {
        node *cur = root;
        for(int i=0;i<s.size();i++){
            int x = s[i]-'a';
            cur = cur->child[x];
        }
        //only look for elements in the subtree of cur
        vector<string> ans;
        dfs(cur,ans,k);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<' ';
        }cout<<'\n';
    }
};

void solve()
{
    int n;cin>>n;
    string s;
    trie t;
    for(int i=0;i<n;i++){
        cin>>s;
        t.insert(s);
    }
    int k,q; cin>>q;
    while(q--){
        cin>>k>>s;
        t.query(s,k);
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);

    solve();
}
