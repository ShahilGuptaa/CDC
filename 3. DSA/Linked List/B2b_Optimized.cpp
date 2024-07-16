#include<bits/stdc++.h>
using namespace std;

//Q - Remove ith node from the end of a linked list

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
    int lenghtll(){
        return len;
    }

    void del_nth_frm_end(int n){ //using fast and slow pointer
        Node* d = head;
        Node *f,*s;
        f=head;
        s=head;
        int temp = n;
        while(temp>0){
            f = f->next;
            temp--;
        }
        if(f==NULL){
            head = head->next;
            return;
        }
        while(f->next!=NULL){
            f = f->next;
            s = s->next;
        }
        Node *no = s->next;
        s->next = no->next;
        delete(no);
        return;
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

    while(1){
        cout<<"Delete nth node from end\n0 -> exit\n";
        
            int num;
            cout<<"Enter n: "; cin>>num;
            if(num==0) return;
            p.del_nth_frm_end(num);
            p.printll();
    }
}

int main()
{
    solve();
}