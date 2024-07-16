#include<bits/stdc++.h>
using namespace std;

string solve()
{
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    set<int> st;
    for(int i=0;i<n;i++) {
        st.insert(arr[i]);
    }
    vector<int> ans;
    for(auto it: st){
        ans.push_back(it);
    }
    int p = ans.size();
    string res;
    if(p%2){
        res = to_string(ans[p/2]);
        res.push_back('.');
        res.push_back('0');
    }else{
        res = to_string((ans[p/2]+ans[p/2 - 1])/2);
        res.push_back('.');
        if((ans[p/2]+ans[p/2 - 1])%2)res.push_back('5');
        else res.push_back('0');
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cout<<solve();
}