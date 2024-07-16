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

//Using Extra Space
Node *mergeLL(Node *l1, Node *l2){
    Node *d1 = l1, *d2 = l2;
    Node *res = NULL,*e = NULL;

    while(d1!=NULL && d2!=NULL){
        if(d1->data >= d2->data){
            Node *temp = new Node(d2->data);
            if(res==NULL){
                res = temp;
                e = temp;
            }else{
                e->next = temp;
                e = temp;
            }
            d2 = d2->next;
        }
        else{
            Node *temp = new Node(d1->data);
            if(res==NULL){
                res = temp;
                e = temp;
            }else{
                e->next = temp;
                e = temp;
            }
            d1 = d1->next;
        }
    }
    while(d1!=NULL){  
        Node *temp = new Node(d1->data);
        e->next = temp;
        d1 = d1->next;
    }
    while(d2!=NULL){  
        Node *temp = new Node(d2->data);
        e->next = temp;
        d2 = d2->next;
    }
    return res;
}

//InPlace
Node *mergeLL_inplace(Node *l1, Node *l2)
{
    Node *res = NULL,*temp = NULL;
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->data > l2->data){
        swap(l1,l2);
    }
    res = l1;
    while(l1!=NULL && l2!=NULL){
        while(l1!=NULL && l1->data <= l2->data){
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1,l2);
    }
    return res;
}

void solve()
{
    Node *ll1 = NULL;
    ll1 = insert_st(ll1,100);
    ll1 = insert_st(ll1,80);
    ll1 = insert_st(ll1,60);
    ll1 = insert_st(ll1,40);
    ll1 = insert_st(ll1,20);
    printList(ll1);

    Node *ll2 = NULL;
    ll2 = insert_st(ll2,90);
    ll2 = insert_st(ll2,70);
    ll2 = insert_st(ll2,60);
    ll2 = insert_st(ll2,30);
    printList(ll2);

    Node *ans = mergeLL(ll1,ll2);
    printList(ans);
    
}

int main()
{
    solve();
}