#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;
//recursive
int rec(string a, string b){
    if(a.compare(b)==0) return 1;
    if(a.size()<=1) return 0;

    string key = a + ' ' + b;

    if(mp.find(key)!=mp.end()) return mp[key];

    int n = a.length();
    int ans = 0;

    for(int i=1;i<n;i++)
    {
        string a1 = a.substr(0,i);
        string a2 = a.substr(i,n-i);

        string b1 = b.substr(0,i);
        string b2 = b.substr(i,n-1);

        //Case 1
        if(rec(a1,b1) && rec(a2,b2)){
            ans = 1;
        }
        b2 = b.substr(0,n-i); //a2 = a.substr(i,n-i);
        b1 = b.substr(n-i,i); //a1 = a.substr(0,i);

        //Case 2
        if(rec(a1,b1) && rec(a2,b2)){
            ans = 1;
        }
    }
    return mp[key] = ans;
}

void solve()
{
    string a,b; //find if a and b are scrambled or not
    cin>>a>>b;
    int n = a.size(), m = b.size();
    if(n!=m){
        cout<<"NO\n";
        return;
    }
    if(n == 0){
        cout<<"YES\n";
        return;
    }
    if(rec(a,b)){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}