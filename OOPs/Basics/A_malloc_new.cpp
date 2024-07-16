#include<bits/stdc++.h>
using namespace std;

int main()
{
    //malloc(5*sizeof(int)) this returns void* pointer
    //we will need to type cast it into the required pointer type - (int*)malloc(5*sizeof(int))

    int *d = (int*)malloc(5*sizeof(int)); //here we have to typecasted to return a int* pointer
    for(int i=0;i<5;i++){
        d[i] = i+1; //d[i] = *(d+i)
        cout<<d[i]<<' ';
    }cout<<'\n';

    int *d2 = new int[5];
    for(int i=0;i<5;i++){
        d2[i] = i+1; //d[i] = *(d+i)
        cout<<d2[i]<<' ';
    }
}