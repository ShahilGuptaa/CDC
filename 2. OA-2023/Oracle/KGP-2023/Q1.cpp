#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

long rearrangeStudents(vector<int> arrA,vector<int> arrB)
{
    int n = arrA.size();
    int m = arrB.size();
    vector<int> a,b;
    a = arrA; b= arrB;

    map<int,long> ma,mb,mp;
    for(int i=0;i<n;i++){
        ma[a[i]]++;
        mp[a[i]]++;
    }
    for(int i=0;i<m;i++){
        mb[b[i]]++;
        mp[b[i]]++;
    }
    for(auto v: mp){
        if(v.second%2!=0){
            return -1;
        }
    }
    long cnt1 = 0,cnt2 = 0;
    vector<pair<long,long>> a1,b1;
    for(auto v:mp)
    {
        int val = v.F;
        int freA = ma[val];
        int freB = mb[val];
        if(freA>freB){
            pair<long,long> p1= {val,(freA-freB)/2};
            a1.push_back(p1);
            cnt1 += (freA-freB)/2;
        }else{
            pair<long,long> p2= {val,(freB-freA)/2};
            a1.push_back(p2);
            cnt2 += (freB-freA)/2;
        }
    }
    lli ans = 0,cnt = 0;
    for(int i=0;i<a1.size();i++)
    {
        if(cnt==cnt1)
        {
            break;
        }
        ans += a1[i].F * a1[i].S;
        cnt += a1[i].S;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    cout<<rearrangeStudents(a,b)<<'\n';
}