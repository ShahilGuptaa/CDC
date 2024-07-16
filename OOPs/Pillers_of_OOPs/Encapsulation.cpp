#include<bits/stdc++.h>
using namespace std;

class student {
private:
    string name; //24 bytes
    int age; //4 byte
    int height; //4 byte
public:
    student(){
        name = "";
        age = 5;
        height = 50; //cm
    }
    int getAge(){ return this->age; }
};

int main()
{
    student sgv;
    cout<<sgv.getAge()<<'\n';
    cout<<sizeof(sgv)<<'\n';
    return 0;
}