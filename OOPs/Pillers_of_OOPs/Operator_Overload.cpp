#include<iostream>
using namespace std;

class A{
public:
    int a,b;
    int add(){
        return a+b;
    }
    void operator+ (A &obj){
        int val1 = this->a;
        int val2 = obj.a;
        cout<<"output "<<val2-val1<<'\n';
    }
    void operator() (){
        cout<<"Main Parenthesis hoon"<<this->a<<"\n";
    }
};

int main()
{
    A obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;
    obj1+obj2; 
    obj1();
}