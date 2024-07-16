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

//Using hash table
//Space Complexity O(n)
int cycle_using_maps(Node* l){
    map<Node*,int> mp;
    while(l!=NULL){
        mp[l]++;
        if(mp[l]>1){
            return 1;
        }
        l = l->next;
    }
    return 0;
}

int cycle_detection(Node* l){
    if(l==NULL || l->next==NULL) return 0;
    Node *s = l, *f = l;

    while(f->next!=NULL && f->next->next!=NULL){
        f = f->next->next;
        s = s->next;
        if(f==s){
            return 1;
        }
    }    
    return 0;
}