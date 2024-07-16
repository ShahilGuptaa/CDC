#include<bits/stdc++.h>
using namespace std;

//Backspacing and checking

void solve()
{
    string s1,s2; cin>>s1>>s2;
    stack<char> st1,st2;
    string fin1,fin2;
    for(int i=0;i<(int)s1.size();i++){
        if(s1[i]!='#')
        {
            st1.push(s1[i]);
        }else{
            st1.pop();
        }
    }
    
    while(!st1.empty()){
        fin1.push_back(st1.top());
        st1.pop();
    }

    for(int i=0;i<(int)s2.size();i++){
        if(s2[i]!='#'){
            st2.push(s2[i]);
        }else{
            st2.pop();
        }
    }
    while(!st2.empty()){
        fin2.push_back(st2.top());
        st2.pop();
    }

    if(fin1==fin2){
        cout<<"1\n";
    }else{
        cout<<"0\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}