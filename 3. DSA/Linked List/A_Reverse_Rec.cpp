#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

class node{
public:
    int data;
    node *next;

    node(int val){
        this->data = val;
        this->next = NULL;
    }
};

node *insert_st(node *head, int val){
    node *temp = new node(val);
    temp->next = head;
    return temp;
}

void printlist(node *head){
    node *d = head;
    while(d!=NULL){
        cout<<d->data<<"->";
        d = d->next;
    }cout<<"NULL\n";
    return;
}

node *reversell(node *head){

    node *par = head;
    //Base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    //recursion call;
    node *f = head->next;
    node *l  = reversell(f);
    f->next = par;
    par->next = NULL;
    return l;
}

int main()
{
    node *list=NULL;
    list = insert_st(list,8);
    list = insert_st(list,7);
    list = insert_st(list,6);
    list = insert_st(list,5);
    list = insert_st(list,4);
    list = insert_st(list,3);
    list = insert_st(list,2);
    list = insert_st(list,1);

    printlist(list);

    list = reversell(list);
    printlist(list);

}