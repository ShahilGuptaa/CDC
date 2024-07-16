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

Node *rotatebyK(Node *head, int k)
{
    if(head==NULL || head->next==NULL) return head;
    
    Node *temp = head;
    Node *e = head;
    int len = 0;

    //Finding length and storing the end node
    while(temp!=NULL){
        e = temp;
        temp = temp->next;
        len++;
    }
    k = (k%len);

    //Location of node to be made NULL
    int p = len - k;
    temp = head;
    for(int i=1;i<p;i++){
        temp = temp->next;
    }

    //Adjusting to the result
    Node* res = temp->next;
    temp->next = NULL;
    e->next = head;
    return res;
}

int main()
{
    Node *ll1 = NULL;
    ll1 = insert_st(ll1,1);
    ll1 = insert_st(ll1,2);
    ll1 = insert_st(ll1,3);
    ll1 = insert_st(ll1,4);
    ll1 = insert_st(ll1,5);
    printList(ll1);

    Node *ans = rotatebyK(ll1,2);
    printList(ans);

}