#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> ans; ans.push_back(a[0]);

    for(int i=1;i<n;i++){
        if(a[i]>ans.back()){
            ans.push_back(a[i]);
        }else{
            int low = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
            ans[low] = a[i];

        }
    }
    cout<<ans.size()<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}