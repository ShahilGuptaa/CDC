#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int ans = 1;
        int x,n; cin>>x>>n;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                int p = (x/i);
                int q = (i);
                
                if(p>=n) ans = max(ans,q);
                if(q>=n) ans = max(ans,p);
            }
        }
        cout<<ans<<'\n';
    }
}