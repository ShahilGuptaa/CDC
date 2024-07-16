#include<bits/stdc++.h>
using namespace std;

//Q - Remove ith node from the start of a linked list

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
    void del_ith(int i){
        if(i>len){
            return;
        }
        len--;
        if(i==1){
            Node *temp = temp;
            head = head->next;
            delete(temp);
        }
        int p = i-1;
        Node *d = head;
        Node *prev = head;
        while(p>0){
            prev = d;
            d = d->next;
            p--;
        }
        prev->next = d->next;
        delete(d);
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
        cout<<"1 -> Delete ith node\nOthers -> exit\n";
        int c; cin>>c;
        if(c==1){
            int num;
            cout<<"Enter i: "; cin>>num;
            p.del_ith(num);
            p.printll();
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