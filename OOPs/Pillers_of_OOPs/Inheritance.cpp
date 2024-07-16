#include<bits/stdc++.h>
using namespace std;

class Human{
public:
    int height;
    int weight;
    int age;
    Human(){
        height = weight = age = 0;
    }
    int getAge(){ return this->age; }
    int setweight(int w){ this->weight = w; }

};
class Male: protected Human {
public:
    string color;
    Male(){
        height = 10;
        color = "Black";
    }
    int getHeight(){return this->height;}
};

int main()
{
    Male obj1;
    cout<<obj1.getHeight()<<'\n';

    return 0;
}