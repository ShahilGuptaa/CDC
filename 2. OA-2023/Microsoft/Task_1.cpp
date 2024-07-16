#include<bits/stdc++.h>
using namespace std;

vector<int> prefix(string &s)
{
    int n = s.size();
    vector<int>a(n);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='?'  ||  s[i] == '<'){
            cnt++;
        }
        else{
            cnt=0;
        }
        a[i]=cnt;
    }
    return a;
}

vector<int> suffix(string &s)
{
    int n = s.size();
    vector<int> b(n);
    int cnt = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='?'  ||  s[i] == '>'){
            cnt++;
        }
        else{
            cnt=0;
        }
        b[i]=cnt;
    }
    return b;
}

int solution(string &S) {
    int n = S.size();
    vector<int> a = prefix(S);
    vector<int>b = suffix(S);
    int ans=0;
    for(int i=0;i<(n-1);i++){
        int x = min(a[i],b[i+1]);
        ans = max(ans,2*x);
    }
    return ans;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<solution(s)<<'\n';
    }
}