#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

Node *insert_st(Node *head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}

void printList(Node *head){
    Node *d = head;
    while(d!=NULL){
        cout<<d->data<<"->";
        d = d->next;
    }cout<<"NULL\n";
    return;
}

Node *add2ll(Node *l1, Node *l2){
    Node *res = NULL, *d;
    int a,b,carry = 0,val = 0;
    while(l1!=NULL || l2!=NULL){
        if(l1==NULL) a = 0;
        else a = l1->data;

        if(l2==NULL) b = 0;
        else b = l2->data;

        val = (a+b+carry);
        carry = val/10;
        val = val%10;

        Node *temp = new Node(val);
        if(res==NULL) {
            res = temp; d= temp;
        }else{
            d->next = temp;
            d = temp;
        }
        if(l1!=NULL)l1 = l1->next;
        if(l2!=NULL)l2 = l2->next;
    }
    if(carry!=0){
        Node *temp = new Node(carry);
        d->next = temp;
    }
    return res;
}

void solve()
{
    Node *ll1 = NULL;
    ll1 = insert_st(ll1,3);
    ll1 = insert_st(ll1,4);
    ll1 = insert_st(ll1,2);
    printList(ll1);

    Node *ll2 = NULL;
    ll2 = insert_st(ll2,9);
    ll2 = insert_st(ll2,7);
    ll2 = insert_st(ll2,6);
    ll2 = insert_st(ll2,5);
    printList(ll2);

    Node *ans = add2ll(ll1,ll2);
    printList(ans);

}

int main()
{
    solve();
}