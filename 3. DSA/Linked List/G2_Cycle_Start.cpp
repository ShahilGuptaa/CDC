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
Node* cycle_start(Node* l){
    map<Node*,int> mp;
    while(l!=NULL){
        mp[l]++;
        if(mp[l]>1){
            return l;
        }
        l = l->next;
    }
    return NULL;
}

Node* cycle_detection(Node* l){
    if(l==NULL || l->next==NULL) return 0;
    Node *s = l, *f = l;
    Node *coll=NULL; //collision pointer
    while(f->next!=NULL && f->next->next!=NULL){
        f = f->next->next;
        s = s->next;
        if(f==s){
            coll = f;
            break;
        }
    }
    //Check for collision of entry pointer and slow ptr
    if(coll!=NULL){
        while(l!=s){
            l = l->next;
            s = s->next;
        }
        return s;
    }
    else return NULL;
}