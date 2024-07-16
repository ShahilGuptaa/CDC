#include<iostream>
using namespace std;

class A{
public:
    void sayHello(){
        cout<<"Hello Shahil\n";
    }
    int sayHello(string name){
        cout<<"Hello "<<name<<'\n';
        return 0;
    }
};

int main()
{
    A obj;
    obj.sayHello();
    cout<<obj.sayHello("Shahil");
    return 0;
}
