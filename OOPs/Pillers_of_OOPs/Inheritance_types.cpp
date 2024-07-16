#include<bits/stdc++.h>
using namespace std;

class Animal{
public:
    int weight;
    int age;
    void speak(){
        cout<<"Speaking\n";
    }

};

class Human{
public:
    string color = "";
    void species(){
        cout<<"HOMO-SAPIENS\n";
    }
};

class Hybrid: public Animal, public Human{

};

int main()
{
    Hybrid obj;
    obj.speak();
    obj.species();
    return 0;
}
