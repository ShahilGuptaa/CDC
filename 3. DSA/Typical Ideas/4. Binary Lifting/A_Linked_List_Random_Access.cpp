#include<bits/stdc++.h>
using namespace std;
using ii =  pair<int,int>;
class node{
public:
    int data; 
    node* next;
    node(){
        data = 0;
        next = NULL;
    }
    node(int n){
        this->data = n;
        this->next = NULL;
    }
};

class linked_list{
public:
    node *head;
    map<pair<node*,int>,node*> nex; //{cur node,2^i}, ind
    int cnt = 0;
    linked_list(){
        head = NULL;
    }
    void insert(int n){
        node *nnode = new node(n);
        nnode->next = head;
        head = nnode;
        cnt++;
        return;
    }
    void print(){
        node *cur = head;
        while(cur!=NULL){
            cout<<cur->data<<' ';
            cur = cur->next;
        } cout<<'\n';
        return;
    }
    node *find_head(){
        return head;
    }
    //Binary lifting
    void preprocessing(){
        node *cur = head;
        while(cur->next!=NULL)
        {
            nex[{cur,0}] = cur->next;
            cur = cur->next; 
        }
        int x = 0;
        for(int i=1;i<20;i++){
            node *cur = head;
            x = 0;
            while(cur!=NULL)
            {
                if( x + (1<<i) < cnt ){ //so that no access is done beyond the end of the linked list
                    nex[{cur,i}] = nex[{nex[{cur,i-1}],i-1}];
                }
                x++;
                cur = cur->next;
            }
        }
    }
    int query(node *cur, int k){
        for(int i=19;i>=0;i--){
            if(k&(1<<i)){
                cur = nex[{cur,i}];
            }
        }
        return cur->data;
    }
};
void solve()
{
    int x,n;cin>>n;
    linked_list l;
    for(int i=0;i<n;i++){
        cin>>x; 
        l.insert(x);
    }
    l.print();
    l.preprocessing();
    int q; cin>>q;
    while(q--){
        node *cur = l.find_head();
        int k; cin>>k;
        cout<<l.query(cur,k)<<'\n';
    }
    
}

int main()
{
    solve();
}