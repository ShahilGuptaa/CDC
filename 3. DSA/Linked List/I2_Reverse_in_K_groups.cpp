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

int len(node *head){
    int cnt = 0;
    node *d = head;
    while(d!=NULL){
        d = d->next;
        cnt++;
    }
    return cnt;
}

node *reverselist(node *head){
    if(head==NULL || head->next == NULL) return head;
    node *p = NULL, *f = head;
    while(head!=NULL){
        f = f->next;
        head->next = p;
        p = head;
        head = f;
    }
    head = p;
    return head;
}

node *reverse_in_grpsk(node *head, int k){

    //Base case
    if(head==NULL || k>len(head)){
        return head;
    }

    //i will reverse the 1st node
    node *par = head;
    int  l = len(head);
    int p = l/k; //no of grps we want to reverse

    
    node *prev = NULL, *f = head;
    for(int i=1;i<=k;i++){
        f = f->next;
        head->next = prev;
        prev = head;
        head = f;
    }
    //prev gives us the req head
    //head = points to (k+1)th element
    node *d = head;
    node *res = reverse_in_grpsk(d,k);
    par->next = res;

    return prev;
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
    //list = reverselist(list);
    //printlist(list);

    list = reverse_in_grpsk(list,3);
    printlist(list);

}