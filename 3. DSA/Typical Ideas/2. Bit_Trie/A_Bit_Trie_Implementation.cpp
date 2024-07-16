#include<bits/stdc++.h>
using namespace std;

struct node{
    node* child[2];
    int cnt;
    node(){
        child[0] = NULL;
        child[1] = NULL;
        cnt = 0;
    }
};

struct trie
{
    node* root;
    trie(){
        root = new node();
    }
    void insert(int n)
    {
        node *cur = root;
        for(int i=30;i>=0;i--)
        {
            cur->cnt++;
            int x = (n&(1<<i)) ? 1: 0;
            if(cur->child[x]==NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->cnt++;
    }
    void del(int n)
    {
        node *cur = root;
        for(int i=30;i>=0;i--)
        {
            cur->cnt--;
            int x = (n&(1<<i)) ? 1: 0;
            if(cur->child[x]==NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->cnt--;
    }
};

int main()
{
    
}