#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    //Default constructor
    Node(){
        val = 0;
        next = NULL;
    }
    //Parameterised Constructor
    Node(int data){
        this->val = data;
        this->next = NULL;
    }
};

class LinkedList{
    Node* head;

public:
    LinkedList(){
        head = NULL;
    }
    void insertNode_End(int val){
        Node *temp = new Node(val); //new node
        if(head==NULL){
            head = temp;
            return;
        }
        Node *p;
        p = head;
        while(p->next!=NULL){
            p = p->next;
        }
        //Insertind node at the last
        p->next = temp;
    }
    void insertNode_start(int val){
        Node *temp = new Node(val); //new node
        temp->next = head;
        head = temp;
        return;
    }
    void printlist(){
        Node *temp; temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }cout<<"NULL\n";
    }
    void reverse(){
        if(head==NULL || head->next==NULL){
            return;
        }
        Node *l; l = NULL;
        Node *r; r = head;
        while(head!=NULL){
            head = head->next;
            r->next = l;
            l = r;
            r = head;
        }
        head = l;
    }
};


void solve()
{
    LinkedList p;
    while(1){
        cout<<"1 -> insert at end\n2 -> insert at beginning\n3 -> print list\n4 -> Reverse\nothers -> exit\n";
        int c; cin>>c;
        if(c==1 || c==2){
            int num;
            cout<<"Enter num to be inserted: ";
            cin>>num;
            if(c==1) p.insertNode_End(num);
            else p.insertNode_start(num);
        }
        else if(c==3){
            p.printlist();
        }
        else if(c==4){
            p.reverse();
        }
        else{
            break;
        }
    }
}

int main()
{
    solve();
}