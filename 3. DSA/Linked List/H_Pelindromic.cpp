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
void printList(Node *head){
    Node *d = head;
    while(d!=NULL){
        cout<<d->data<<"->";
        d = d->next;
    }cout<<"NULL\n";
    return;
}

Node *insert_st(Node *head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}

int is_pelindrome(Node* l){
    //Find middle of the linked list
    //In case of even sized linked list, take the 1st middle ele
    Node *s = l,*f = l;
    while(f->next!=NULL && f->next->next!=NULL){
        f = f->next->next;
        s = s->next;
    }
    //s will point to middle element now
    cout<<s->data<<'\n';

    Node *d = s->next;
    printList(d);
    
    //now we will reverse the linked list d
    Node *prev = NULL;
    Node *forw = d;
    while(forw!=NULL){
        forw = forw->next;
        d->next = prev;
        prev = d;
        d = forw;
    }
    d = prev;
    printList(d);

    //Check whether the list  d and l is common or nor
    while(d!=NULL){
        if(d->data!=l->data) return 0;
        d = d->next;
        l = l->next;
    }
    return 1;
}

int main()
{
    Node *ll1 = NULL;
    ll1 = insert_st(ll1,1);
    ll1 = insert_st(ll1,2);
    ll1 = insert_st(ll1,3);
    ll1 = insert_st(ll1,2);
    ll1 = insert_st(ll1,1);
    printList(ll1);

    cout<<is_pelindrome(ll1)<<'\n';

}