#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    string p = "";
    for(int i=0;i<n;i++){
        if(i%2==0){
            p.push_back(s[i/2]);
        }else{
            p.push_back(s[n - (i+1)/2]);
        }
    }
    cout<<p<<endl;
}