#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int arr[26] = {0};

struct node{
    node* child[26];
    node(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

//Note if you are printing all unique substings, it will take O(N^3)
//for printing we can use set<string> and do a bruteforce - simple approach
//counting can be done in O(N^2)
struct trie{
    node *root;
    lli total_nodes = 0;
    //vector<string> all_distict_substrings;
    trie(){
        root = new node();
    }
    void insert(string s, int st)
    {
        node* cur = root;
        string temp = "";
        for(int i=st;i<s.size();i++)
        {
            temp.push_back(s[i]);
            if(cur->child[s[i]-'a']==NULL)
            {
                //all_distict_substrings.push_back(temp);
                total_nodes++;
                cur->child[s[i]-'a'] = new node();
            }
            cur = cur->child[s[i]-'a'];
        }
    }
    lli count_distinct_substring()
    {
        // for(auto i: all_distict_substrings){
        //     cout<<i<<' ';
        // }cout<<"{empty}\n";
        return total_nodes+1;
    }
};

void solve()
{
    string s; cin>>s;
    int n = s.size();
    trie t;
    for(int i=0;i<n;i++){
        t.insert(s,i); //inserting all the substrings
    }
    cout<<t.count_distinct_substring()<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}