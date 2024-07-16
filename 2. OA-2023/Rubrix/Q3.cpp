#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

void solve(){
    int n;
    cin>>n;
    int ban[3],hyd[3];
    for(int i=0;i<3;i++)cin>>ban[i];
    for(int i=0;i<3;i++)cin>>hyd[i];
    int maxdif_going = 0;
    int maxdif_coming = 0;
    int ans = n;
    for(int i=0;i<3;i++){
        if(hyd[i]-ban[i]>maxdif_going)maxdif_going = hyd[i]-ban[i];
        if(ban[i]-hyd[i]>maxdif_coming)maxdif_coming = ban[i]-hyd[i];
    }
    if(maxdif_going>0)ans+=n*maxdif_going;
    if(maxdif_coming>0){
        int temp = ans;
        ans+=temp*maxdif_coming;
    }
    cout<<ans<<endl;
}

int32_t main(){
    IOS
    solve();
    return 0;
}