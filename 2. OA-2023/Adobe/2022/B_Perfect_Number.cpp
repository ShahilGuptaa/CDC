#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

void solve(){
    lli x,z;cin>>x>>z;
    vector<string> ans;
    for(int last=1;last<=9;last++){
        string temp;
        temp.push_back('0'+last);
        lli carry = 0;
        for(int i=1;i<x;i++){
            lli l = (temp[i-1] - '0');
            lli num = z*l+ carry;
            temp.push_back(num%10 + '0');
            carry = num/10;
        }
        if(carry+(temp[temp.size()-1] - '0')*z==last){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }     
    }
    if(ans.size()==0){
        cout<<"-1\n";
        return;
    }
    sort(ans.begin(),ans.end());
    for(auto &v:ans){
        if(v[0]!='0'){
            cout<<v<<'\n';
            return;
        }
    }
    cout<<"-1\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}