#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int arr[26] = {0};

struct node{
    node* child[26];
    lli cnt;
    node(){
        cnt = 0;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

struct trie{
    node *root;
    lli cnt = 0;
    trie(){
        root = new node();
    }
    void insert(string s, int st)
    {
        node* cur = root;
        string temp = "";
        for(int i=st;i<s.size();i++)
        {
            cur->cnt++;
            if(cur->child[s[i]-'a']==NULL)
            {
                cur->child[s[i]-'a'] = new node();
            }
            cur = cur->child[s[i]-'a'];
        }
    }
    void dfs(node* cur, int bads, int &k)
    {
        if(bads<=k){
            cnt++;
        }
        for(int i=0;i<26;i++)
        {
            if(cur->child[i]){
                dfs(cur->child[i], bads+(!arr[i]) ,k);
            }
        }
    }
    lli cnt_good_substrings(int k){
        dfs(root,0,k);
        return cnt;
    }
};

void solve()
{
    string s; cin>>s;
    int n = s.size();
    string is_good; cin>>is_good;
    for(int i=0;i<26;i++){
        arr[i] = is_good[i] - '0';
    }
    trie t;
    for(int i=0;i<n;i++){
        t.insert(s,i);
    }
    int k; cin>>k;
    cout<<t.cnt_good_substrings(k)-1<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}