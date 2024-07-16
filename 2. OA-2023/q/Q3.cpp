#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> st,vector<int> en)
{
    vector<pair<int,int>> events;
    for(int i=0;i<n;i++){
        events.push_back({st[i],0});
        events.push_back({en[i],1});
    }
    sort(events.begin(),events.end());
    int active=0;
    int ans = 0;
    for(auto i:events){
        if(i.second==0){
            active++;
        }else{
            active--;
        }
        ans = max(ans,active);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin>>n;
    vector<int> st,en;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        st.push_back(x);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        en.push_back(x);
    }
    cout<<solve(n,st,en);
}