#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

struct manacher
{
    vector<int> p;
    lli ans = 0;

    void run_manacher(vector<lli> s)
    {
        int n = s.size();
        p.assign(n,1);
        int l=1,r=1;

        for(int i=1;i<n;i++)
        {
            p[i] = max(0,(min(r-i,p[l+r-i]))); //kickstart for ith indexed centre
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]])
            {
                p[i]++;
            }
            if(i+p[i]>r){
                l = i-p[i];
                r = i+p[i];
            }
        }
        for(auto v:p)
        {
            ans += v/2;
        }
    }

    //processed string
    void build(vector<lli> s){
        vector<lli> t;
        for(auto v:s){
            t.push_back(-1);
            t.push_back(v);
        }
        t.push_back(-1);
        run_manacher(t);
    }

    lli get()
    {
        return ans;
    }
}m;


void solve()
{
    int n; cin>>n;
    vector<lli> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    m.build(s);
    lli ans = 1ll*(n)*(n+1)/2 - m.get();
    cout<<ans+1<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}