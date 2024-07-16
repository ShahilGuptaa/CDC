#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

void solve()
{
    lli n;cin>>n;
    vector<lli> v(n+2,0);
    lli sum = 0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sum += v[i];
    }
    vector<lli> pre (n+2,0), suff(n+2);
    for(int i=1;i<=n;i++){
        if(v[i] > pre[i-1]) {
            pre[i] = pre[i-1]+1;
        }else{
            pre[i] = v[i];
        }
    }
    for(int i=n;i>=1;i--){
        if(v[i] > suff[i+1]){
            suff[i] = suff[i+1]+1;
        }else{
            suff[i] = v[i];
        }
    }
    lli ans = sum;
    for(int i=1;i<n;i++){
        lli p = pre[i-1], s = suff[i+1];
        lli temp = min(p,s);
        if(v[i]<=temp) temp = v[i]-1;
        ans = min(ans, sum - (temp*(temp+1)) - (temp+1) );
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}