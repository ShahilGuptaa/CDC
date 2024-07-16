#include<iostream>
using namespace std;

class A{
public:
    void func1(){
        cout<<"Function 1\n";
    }
};

class B: public A{
public:
    void func2(){
        cout<<"Function 2\n";
    }
};
class C: public A{
public:
    void func3(){
        cout<<"Function 3\n";
    }
};

int main()
{
    B obj2;
    obj2.func1(); obj2.func2(); 
    cout<<'\n';
    C obj3;
    obj3.func1(); obj3.func3();
}
