#include<bits/stdc++.h>
using namespace std;

class Hero
{
private:
    int health;
public:
    char *name;
    int level;
    static int time_limit_for_game; //this is independent for all
    Hero(){
        cout<<"Default Constructer\n";
        name = new char[20];
    }
    Hero(int health, int level, char name[]){
        this->health = health;
        this->level = level;
        strcpy(this->name,name);
    }
    static int random(int p){
        time_limit_for_game = p;
        return time_limit_for_game;
    }
    void print(){
        cout<<"Name: "<<this->name<<" Health: "<<this->health<<" Level: "<<this->level<<'\n';
    }
};

int Hero::time_limit_for_game = 5; //initilizing (:: - this is scope resolution operator)

int main()
{
    cout<<Hero::time_limit_for_game<<'\n';
    cout<<Hero::random(100)<<'\n';
    return 0;
}
