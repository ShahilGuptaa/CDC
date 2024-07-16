#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int getAnagramPeriod(string &s)
{
    int n= s.length();
    map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    if(mp.size()==1){
        return 1;
    }else{
        auto it = mp.begin();
        int p1 = it->second;
        it++;
        int p2 = it->second;
        it++;
        int hcf = __gcd(p1,p2);
        while(it!=mp.end()){
            hcf = __gcd(hcf,it->second);
            it++;
        }
        int ans = 0;
        for(auto i: mp){
            ans += i.second/hcf;
        }
        return ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t;
    while(t--){ 
        string s; cin>>s;
        cout<<getAnagramPeriod(s)<<'\n';
    }
}