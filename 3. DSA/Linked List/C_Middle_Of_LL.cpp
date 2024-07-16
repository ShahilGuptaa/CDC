#include<bits/stdc++.h>
using namespace std;

//Q - Find middle element of a linked list
//[1 2 3 4 5] return 3
//[1 2 3 4 5 6] return 4(2nd middle element)

class Node{
public:
    int val;
    Node *next;
    Node(int data){
        this->val = data;
        this->next = NULL;
    }
};

class LL{
    Node *head = NULL;
    Node *e = NULL;
    int len = 0;
public:
    void insert_start(int num){
        len++;
        Node *temp = new Node(num);
        temp->next = head;
        head = temp;
        if(head->next==NULL){
            e = head;
        }
        return;
    }
    void insert_end(int num){
        len++;
        Node *temp = new Node(num);
        if(head==NULL){
            head = temp;
            e = head;
            return;
        }
        e->next = temp;
        e = temp;
        return;
    }
    void printll(){
        Node *p = head;
        while(p!=NULL){
            cout<<p->val<<"->";
            p = p->next;
        }cout<<"NULL\n";
    }
    int middle(){
        //Find length of ll and then find (n/2 + 1)th element: 1 based indexind
        //Optimized
        if(head->next==NULL){
            return head->val;
        }
        Node *s,*f;
        s = head;
        f = head;

        while(f!=NULL && f->next!=NULL){
            s = s->next;
            f = f->next->next;
        }
        return s->val;
    }

};

void solve()
{
    LL p;
    p.insert_end(100);
    p.insert_end(200);
    p.insert_start(50);
    p.insert_start(25);
    p.insert_end(225);
    p.insert_start(1);
    p.printll();

    cout<<p.middle()<<'\n';
}

int main()
{
    solve();
}