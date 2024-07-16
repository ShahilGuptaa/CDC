#include<bits/stdc++.h>
using namespace std;

class Dog{
public:
    int weight, age;
    void speak(){
        cout<<"BARK\n";
    }

};

class Human{
public:
    int weight, age;
    void speak(){
        cout<<"Hello!\n";
    }
};

class mul_inheri: public Dog, public Human{

};

int main()
{
    mul_inheri obj;
    cout<<obj.Dog::age<<'\n';
    obj.Human::speak();
    return 0;
}
