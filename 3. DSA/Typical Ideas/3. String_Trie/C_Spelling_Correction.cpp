//Given a set of strings. Answer Q queires of the form
//? S K: Find all strings in set that have atmost K position mismatch with S

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
    vector<string> ans;
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
    void search(node *cur, int pos, int k,string &s)
    {
        if(k<0) return; //Pruning

        if(pos==s.size()){
            for(auto v: cur->wend){
                ans.push_back(v);
            }
        }
        for(int i=0;i<26;i++)
        {
            if(cur->child[i]){
                int x = (s[pos]-'a')==i ? 0 : 1;
                search(cur->child[i],pos+1,k-x,s);
            }
        }
    }
    void query(string s, int k)
    {
        node *cur = root;
        search(cur,0,k,s);
        for(auto i: ans) cout<<i<<'\n';
        cout<<'\n';
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
        cin>>s>>k;
        t.query(s,k);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
