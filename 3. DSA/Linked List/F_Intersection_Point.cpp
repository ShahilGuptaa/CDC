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

int len(Node *l){
    Node *d = l;
    int i = 0;
    while(d!=NULL){
        i++;
        d = d->next;
    } 
    return i;
}

Node *intersection(Node* l1, Node *l2){
    int len1 = len(l1);
    int len2 = len(l2);
    if(len1 < len2){
        swap(l1,l2);
        swap(len1,len2);
    }
    int diff = len1-len2;
    for(int i=1;i<=diff;i++){
        l1 = l1->next;
    }
    while(l1!=NULL && l2!=NULL){
        if(l1==l2){
            return l1;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return NULL;
}
Node *intersection_small(Node *l1, Node *l2){
    Node *d1 = l1, *d2 = l2;
    while(d1!=d2){
        if(d1==NULL) d1 = l2;
        else d1 = d1->next;

        if(d2==NULL) d2 = l1;
        else d2 = d2->next;
    }
    return d1;
}