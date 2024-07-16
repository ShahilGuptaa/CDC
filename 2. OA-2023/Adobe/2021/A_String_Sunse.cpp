#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

lli solve(string s1, string s2)
{
    int n = s2.size();
    char a = s1[0];
    char b = s1[1];
    char c = s1[2];

    vector<lli> pre(n,0);
    vector<lli> suff(n,0);
    for(int i=0;i<n;i++)
    {
        if(i!=0) pre[i] = pre[i-1];

        if(s2[i]==a){
            pre[i]++;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i!=n-1) suff[i] = suff[i+1];
        if(s2[i]==c)
        {
            suff[i]++;
        }
    }
    lli ans = 0;
    for(int i=0;i<n;i++)
    {
        if(s2[i]==b)
        {
            ans += pre[i]*suff[i];
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s1,s2; cin>>s1>>s2;
    cout<<solve(s1,s2)<<'\n';
}