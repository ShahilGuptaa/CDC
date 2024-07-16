#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second

char closest(lli x,lli y){
    lli dist = INF;
    int ans;
    for(int i=0;i<26;i++)
    {
        if((x-i)*(x-i)+(y-i)*(y-i)<dist){
            ans = i;
            dist = (x-i)*(x-i)+(y-i)*(y-i);
        }
    }
    int cnt = 0;
    for(int i=0;i<26;i++)
    {
         if((x-i)*(x-i)+(y-i)*(y-i)==dist){
            cnt++;
         }
    }
    if(cnt>1) return '*';
    else return ('A'+ans);
}

void solve()
{
    lli n;cin>>n;
    string ans;
    for(int i=0;i<n;i++)
    {
        ii xy; cin>>xy.F>>xy.S;
        ans.push_back(closest(xy.F,xy.S));
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}